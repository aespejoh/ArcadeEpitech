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
#include "IGame.hpp"
#include <dlfcn.h>
#include <Utils.hpp>
#include <Exception.hpp>

#define NCURSES_PATH "./lib/arcade_ncurses.so"
#define SFML_PATH "./lib/arcade_sfml.so"
#define SDL2_PATH "./lib/arcade_sdl2.so"
#include <Utils.hpp>
#include <Exception.hpp>

class Core {
    public:
        Core(const std::string&);
        ~Core() = default;
        const std::vector<IDisplayModule *> &getLibs() const;
        void loadlib(const std::string &lib_path, const std::string &active_path);
        void loadgame(const std::string &game_path);
        IDisplayModule *getActiveGfx() const;
        const std::vector<IGame *> &getGames() const;
        int getNumLib(const char *);
        void gameLoop();
        void sepEvents();

    private:
        IDisplayModule *_activeGfx;
        std::vector<IDisplayModule*> _libs;
        std::vector<IGame*> _games;
        char _key;
        int _i;
};

#endif //GLOBALPROJECT_CORE_H
