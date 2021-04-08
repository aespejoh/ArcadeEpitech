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

#define HEAD 'A'
#define FOOD '8'

class SnakeGame : public IGame {
    public:
        SnakeGame();
        void put(unsigned int y, unsigned int x, char item) override;
        void createMap(unsigned int width, unsigned int height);
        void printMap();
        void loadMap() override;
        array_t getArray() override;
        void update(char input) override;
    private:
        std::map<char, int> movement_Input;
};

#endif //GLOBALPROJECT_SNAKEGAME_HPP
