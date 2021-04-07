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

Core::Core(std::string lib)
{
    loadlib("./lib/arcade_sfml.so", lib);
    loadlib("./lib/arcade_sdl2.so", lib);
    loadlib("./lib/arcade_ncurses.so", lib);
    setActiveGfx(lib);
    getActiveGfx()->init();
    _activeGfx = nullptr;
}

IDisplayModule *Core::getActiveGfx() const
{
    return _activeGfx;
}
