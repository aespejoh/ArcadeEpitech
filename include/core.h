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
#include "IGame.hpp"
#include <dlfcn.h>
#include <Utils.hpp>
#include <Exception.hpp>

#define NCURSES_PATH "./lib/arcade_ncurses.so"
#define SFML_PATH "./lib/arcade_sfml.so"
#define SDL2_PATH "./lib/arcade_sdl2.so"

class Core {
    public:
        Core();
        ~Core() = default;
        const std::vector<IDisplayModule *> &getLibs() const;
        void setActiveGfx(std::string libPath);
        void loadlib(const std::string &lib_path, const std::string &active_path);
        void loadgame(const std::string &game_path);
        IDisplayModule *getActiveGfx() const;
        const std::vector<IGame *> &getGames() const;

    private:
        IDisplayModule *_activeGfx;
        std::vector<IDisplayModule*> _libs;
        std::vector<IGame*> _games;

};

#endif //GLOBALPROJECT_CORE_H
