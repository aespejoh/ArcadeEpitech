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

int main(int ac, char **av)
{
    SnakeGame game;
    game.createMap(30,20);
    game.put(4,7, '8');
    game.printMap();

    if (ac != 2) {
        utils::usagePrompt();
        return 84;
    }
    try {
        Core core(av[1]);
        core.getActiveGfx()->printLevel(game.getArray(),10, 10);
    } catch (MainException &exception) {
        std::cout << "Error: " << exception.what();
        return 84;
    }
    return 0;
}
