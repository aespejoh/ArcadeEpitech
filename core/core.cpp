/*
** EPITECH PROJECT, 2021
** globalProject
** File description:
** Created by aespejo,
*/

#include "../include/core.h"

void Core::loadlib(const std::string& lib_path)
{
    IDisplayModule *lib;
    typedef IDisplayModule* (*fptr)();
    fptr func;
    void *handle = dlopen(lib_path.c_str(), RTLD_LAZY);
    if (handle == nullptr)
        return;
    func = (fptr)dlsym(handle, "create");
    lib = (IDisplayModule*)func();
    _libs.push_back(lib);
}

const std::vector<IDisplayModule *> &Core::getLibs() const
{
    return _libs;
}
