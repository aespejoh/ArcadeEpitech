/*
** EPITECH PROJECT, 2021
** globalProject
** File description:
** Created by aespejo,
*/

#include "core.h"

void Core::loadlib(const std::string& lib_path, const std::string &active_path)
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

Core::Core(const std::string& lib)
{
    _i = getNumLib(lib.c_str());
    _key = 0;
    _activeGfx = nullptr;
    loadlib(SFML_PATH, lib);
    loadlib(SDL2_PATH, lib);
    loadlib(NCURSES_PATH, lib);
    loadgame("./lib/arcade_nibbler.so");
    _activeGame->loadMap();
}

IDisplayModule *Core::getActiveGfx() const
{
    return _activeGfx;
}

void Core::loadgame(const std::string &game_path)
{
    IGame *game;
    typedef IGame* (*fptr)();
    fptr func;
    void *handle = dlopen(game_path.c_str(), RTLD_LAZY);
    if (!handle) {
        std::cout << dlerror() << std::endl;
        return;
    }
    dlerror();
    func = (fptr)dlsym(handle, "create");
    game = (IGame*)func();
    _activeGame = game;
    _games.push_back(game);
}

const std::vector<IGame *> &Core::getGames() const
{
    return _games;
}

int Core::getNumLib(const char *libPath)
{
    if (std::strcmp(libPath, SFML_PATH) == 0)
        return 0;
    else if(std::strcmp(libPath, SDL2_PATH) == 0)
        return 1;
    else if (std::strcmp(libPath, NCURSES_PATH) == 0)
        return 2;
    return 3;
}

void Core::gameLoop()
{
    _activeGfx->init();
    while (!_activeGfx->getQuit()) {
        _key = _activeGfx->getInput();
        _activeGame->update(_key);
        _activeGfx->printLevel(_activeGame->getArray(), 10, 10);
        sepEvents();
        _activeGfx->refresh();
    }
    _activeGfx->stop();
}

void Core::sepEvents()
{
    if (_key == KEYUP) {
        _i += 1;
        if (_i > 2)
            _i = 0;
        _activeGfx->stop();
        _activeGfx = getLibs()[_i];
        _activeGfx->init();
    }
    if (_key == KEYDOWN) {
        _i -= 1;
        if (_i > 2)
            _i = 0;
        _activeGfx->stop();
        _activeGfx = getLibs()[_i];
        _activeGfx->init();
    }
}
