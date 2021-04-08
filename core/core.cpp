/*
** EPITECH PROJECT, 2021
** globalProject
** File description:
** Created by aespejo,
*/

#include "core.h"

void Core::loadlib(const std::string& lib_path)
{
    IDisplayModule *lib;
    typedef IDisplayModule* (*fptr)();
    fptr func;
    void *handle = dlopen(lib_path.c_str(), RTLD_LAZY);
    if (!handle) {
        std::cout << dlerror() << std::endl;
        return;
    }
    dlerror();
    func = (fptr)dlsym(handle, "create");
    lib = (IDisplayModule*)func();
    if (lib_path == active_path)
        _activeGfx = lib;
    _libs.push_back(lib);
    //if (dlclose(handle) != 0)
    //    exit(84);

}

const std::vector<IDisplayModule *> &Core::getLibs() const
{
    return _libs;
}

void Core::setActiveGfx(std::string libPath)
{

}

Core::Core(std::string lib)
{
    loadlib("./lib/arcade_sfml.so", lib);
    loadlib("./lib/arcade_sdl2.so", lib);
    loadlib("./lib/arcade_ncurses.so", lib);
    getActiveGfx()->init();
}

IDisplayModule *Core::getActiveGfx() const
{
    return _activeGfx;
}

void Core::loadgame(const std::string &game_path)
{
    IGame *lib;
    typedef IGame* (*fptr)();
    fptr func;
    void *handle = dlopen(game_path.c_str(), RTLD_LAZY);
    if (!handle) {
        std::cout << dlerror() << std::endl;
        return;
    }
    dlerror();
    func = (fptr)dlsym(handle, "create");
    lib = (IGame*)func();
    _games.push_back(lib);
    //if (dlclose(handle) != 0)
    //    exit(84);
}

const std::vector<IGame *> &Core::getGames() const
{
    return _games;
}

void Core::loadlibs()
{
    loadlib("./lib/arcade_sfml.so");
    loadlib("./lib/arcade_sdl2.so");
    loadlib("./lib/arcade_ncurses.so");
}

int Core::getNumLib(char *libPath)
{
    int i = 3;

    if (std::strcmp(libPath, "lib/arcade_sfml.so") == 0)
        i = 0;
    else if(std::strcmp(libPath, "lib/arcade_sdl2.so") == 0)
        i = 1;
    else if (std::strcmp(libPath, "lib/arcade_ncurses.so") == 0)
        i = 2;
    return i;
}

void Core::gameLoop()
{
    while (!_lib->getQuit()) {
        _lib->initMenu();
        _key = _lib->getInput();
        sepEvents();
    }
    _lib->stop();
}

void Core::sepEvents()
{
    if (_key == KEYUP) {
        _i += 1;
        if (_i > 2)
            _i = 0;
        _lib->stop();
        _lib = getLibs()[_i];
        _lib->init();
    }
    if (_key == KEYDOWN) {
        _i -= 1;
        if (_i > 2)
            _i = 0;
        _lib->stop();
        _lib = getLibs()[_i];
        _lib->init();
    }
}
