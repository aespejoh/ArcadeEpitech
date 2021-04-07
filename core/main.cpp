/*
** EPITECH PROJECT, 2021
** B-OOP-400-BAR-4-1-arcade-oriol.moles-teiga
** File description:
** main
*/

#include <iostream>
#include <core.h>
#include <IGame.hpp>
#include "snakeGame.hpp"

void usage()
{
    std::cout << "USAGE" << std::endl;
    std::cout << "./arcade [graphical library]" << std::endl;
    std::cout << "Possible graphical libraries:" << std::endl;
    std::cout << "\t- lib/arcade_sfml.so" << std::endl;
    std::cout << "\t- lib/arcade_sdl2.so" << std::endl;
    std::cout << "\t- lib/arcade_ncurses.so" << std::endl;
}

int main(int ac, char **av)
{
    if (ac != 2) {
        usage();
        return 84;
    }
    SnakeGame game;
    game.createMap(20,20);
    game.put(1,1,'5');
    game.printMap();
    Core core(av);
    //core.loadlib("./lib/arcade_sfml.so");
/*
    if (ac != 2) {
        utils::usagePrompt();
        return 84;
    }

    try {
        int i;
        Core core;
        core.loadlib("./lib/arcade_sfml.so");
        core.loadlib("./lib/arcade_sdl2.so");
        core.loadlib("./lib/arcade_ncurses.so");
        std::cin >> i;
        core.getLibs()[i++]->init();
    } catch (MainException &exception) {
        std::cout << "Error: " << exception.what();
        return 84;
    }
    return 0;
*/
}
