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
    IGame *game = nullptr;
    if (ac != 2) {
        utils::usagePrompt();
        return 84;
    }
    try {
        int i;
        Core core(av[1]);
        core.loadgame("./lib/arcade_nibbler.so");
        game = core.getGames()[0];
        core.getActiveGfx()->printLevel(game->getArray(),10, 10);
    } catch (MainException &exception) {
        std::cout << "Error: " << exception.what();
        return 84;
    }
    return 0;
}
