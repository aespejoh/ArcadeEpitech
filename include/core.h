/*
** EPITECH PROJECT, 2021
** globalProject
** File description:
** Created by aespejo,
*/
#ifndef GLOBALPROJECT_CORE_H
#define GLOBALPROJECT_CORE_H

#include <vector>
#include "iDisplayModule.hpp"
#include <dlfcn.h>

class Core {
    public:
        Core() = default;
        ~Core() = default;
        void loadlib(const std::string&);

    const std::vector<IDisplayModule *> &getLibs() const;

    private:
        std::vector<IDisplayModule*> _libs;
};

#endif //GLOBALPROJECT_CORE_H
