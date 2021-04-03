/*
** EPITECH PROJECT, 2021
** B-OOP-400-BAR-4-1-arcade-oriol.moles-teiga
** File description:
** main
*/

#include <iostream>
#include <core.h>

int main(int ac, char **av)
{
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
}
