/*
** EPITECH PROJECT, 2021
** globalProject
** File description:
** Created by aespejo,
*/
#ifndef GLOBALPROJECT_SNAKEGAME_HPP
#define GLOBALPROJECT_SNAKEGAME_HPP

#include "IGame.hpp"
#include <string>
#include <vector>
#include <iostream>

class SnakeGame : public IGame {
    public:
        void put(unsigned int y, unsigned int x, char item) override;
        void createMap(unsigned int width, unsigned int height);
        void printMap();
        void loadMap() override;
        array_t getArray() override;
};

#endif //GLOBALPROJECT_SNAKEGAME_HPP
