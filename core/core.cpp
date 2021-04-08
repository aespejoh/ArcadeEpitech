/*
** EPITECH PROJECT, 2021
** globalProject
** File description:
** Created by aespejo,
*/

#include "core.h"

Core::Core(char **av, IGame *game)
{
    _key = 0;
    loadlibs();
    _game = game;
    _i = getNumLib(av[1]);
    if (_i >= 0 && _i <= 2)
        _lib = getLibs()[_i];
    _lib->initWindow();
    gameLoop();
}

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
    _libs.push_back(lib);
    //if (dlclose(handle) != 0)
    //    exit(84);

}

const std::vector<IDisplayModule *> &Core::getLibs() const
{
    return _libs;
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
        //_lib->printLevel(_game->getArray(), 10, 10);
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
        if (_i < 0)
            _i = 2;
        _lib->stop();
        _lib = getLibs()[_i];
        _lib->init();
    }
}
