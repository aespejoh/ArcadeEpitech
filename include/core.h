/*
** EPITECH PROJECT, 2021
** globalProject
** File description:
** Created by aespejo,
*/
#ifndef GLOBALPROJECT_CORE_H
#define GLOBALPROJECT_CORE_H

#include <cstring>
#include <vector>
#include "iDisplayModule.hpp"
#include <dlfcn.h>
#include <Utils.hpp>
#include <Exception.hpp>

class Core {
    public:
        explicit Core(char **);
        ~Core() = default;
        void loadlib(const std::string&);
        void loadlibs();
        int getNumLib(char *);
        const std::vector<IDisplayModule *> &getLibs() const;
        void gameLoop();
        void sepEvents();

    private:
        std::vector<IDisplayModule*> _libs;
        IDisplayModule *_lib;
        char _key;
        int _i;
};

#endif //GLOBALPROJECT_CORE_H
