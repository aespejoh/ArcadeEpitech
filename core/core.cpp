/*
** EPITECH PROJECT, 2021
** globalProject
** File description:
** Created by aespejo,
*/

#include "core.h"

void Core::loadlib(const std::string& lib_path, const std::string& active_path)
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

Core::Core()
{
    _activeGfx = nullptr;
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
