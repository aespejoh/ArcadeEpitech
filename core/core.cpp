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
    std::string fullPath = "./lib/" + lib_path;
    void *handle = dlopen(fullPath.c_str() , RTLD_LAZY);

    if (!handle) {
        std::cout << dlerror() << std::endl;
        return;
    }
    dlerror();
    func = (fptr)dlsym(handle, "create");
    lib = (IDisplayModule*)func();
    if (active_path.find(lib_path) != std::string::npos)
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
    _i = getNumLib(lib);
    _key = 0;
    _menu = true;
    _game = false;
    _activeGfx = nullptr;
    loadlib(SFML_FILE, lib);
    loadlib(SDL2_FILE, lib);
    loadlib(NCURSES_FILE, lib);
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

int Core::getNumLib(std::string lib)
{
    std::ifstream my_file(lib);

    if (my_file.good()) {
        if (lib.find(SFML_FILE) != std::string::npos)
            return 0;
        else if (lib.find(SDL2_FILE) != std::string::npos)
            return 1;
        else if (lib.find(NCURSES_FILE) != std::string::npos)
            return 2;
    }
    throw MainException("Incorrect or corrupt library\n");
}

void Core::gameLoop()
{
    if (_activeGfx == NULL)
        throw MainException("No library has been found.\n");
    _activeGfx->init();
    while (!_activeGfx->getQuit()) {
        _key = _activeGfx->getInput(_menu);
        _activeGame->update(_key);
        /*if (_menu) {
            _name += _activeGfx->getUsername();
            std::cout << _name << std::endl;
        }*/
        if (_menu)
            _activeGfx->initMenu();
        else
            _activeGfx->printLevel(_activeGame->getArray(), 10, 10);
        sepEvents();
        _activeGfx->refresh();
    }
    _activeGfx->stop();
}

void Core::sepEvents()
{
    switch (_key) {
        case KEYUP:
            _i += 1;
            if (_i > 2)
                _i = 0;
            _activeGfx->stop();
            _activeGfx = getLibs()[_i];
            _activeGfx->init();
            break;
        case KEYDOWN:
            _i -= 1;
            if (_i < 0)
                _i = 2;
            _activeGfx->stop();
            _activeGfx = getLibs()[_i];
            _activeGfx->init();
            break;
        case MOUSELEFT:
            _menu = false;
            _game = true;
            break;
        default:
            break;
    }
}

void Core::manageEvents()
{
    while (_activeGfx->getEvent()) {

    }
}
