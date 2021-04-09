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
#include <fstream>
#include "iDisplayModule.hpp"
#include "IGame.hpp"
#include <dlfcn.h>
#include <Utils.hpp>
#include <Exception.hpp>
#include <Utils.hpp>
#include <Exception.hpp>

#define NCURSES_FILE "arcade_ncurses.so"
#define SFML_FILE "arcade_sfml.so"
#define SDL2_FILE "arcade_sdl2.so"

class Core {
    public:
        Core(const std::string&);
        ~Core() = default;
        const std::vector<IDisplayModule *> &getLibs() const;
        void loadlib(const std::string &lib_path, const std::string &active_path);
        void loadgame(const std::string &game_path);
        IDisplayModule *getActiveGfx() const;
        const std::vector<IGame *> &getGames() const;
        int getNumLib(std::string lib);
        void gameLoop();
        void sepEvents();
    private:
        IDisplayModule *_activeGfx;
        IGame *_activeGame;
        std::vector<IDisplayModule*> _libs;
        std::vector<IGame*> _games;
        char _key;
        int _i;
};

#endif //GLOBALPROJECT_CORE_H
