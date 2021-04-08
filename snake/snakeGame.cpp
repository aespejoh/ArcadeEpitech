/*
** EPITECH PROJECT, 2021
** globalProject
** File description:
** Created by aespejo,
*/
#include "snakeGame.hpp"

extern "C" IGame* create()
{
    return new SnakeGame();
}


void SnakeGame::createMap(unsigned int width, unsigned int height)
{
    array_t array(height, std::vector<char> (width, '7'));
    for (int i = 0; i < width; i++)
        array[0][i] = '1';
    for (int i = 0; i < width; i++)
        array[height-1][i] = '1';
    for (int i = 0; i < height; i++)
        array[i][0] = '0';
    for (int i = 0; i < height; i++)
        array[i][width - 1] = '0';
    array[0][0] = '2';
    array[0][width - 1] = '3';
    array[height - 1][0] = '4';
    array[height - 1][width - 1] = '5';
    _array = array;
}

void SnakeGame::loadMap()
{
}

array_t SnakeGame::getArray()
{
    return _array;
}

void SnakeGame::put(unsigned int y, unsigned int x, char item)
{
    _array[y][x] = item;
}

void SnakeGame::printMap()
{
    for (auto &i : _array) {
        for (auto &e: i)
            std::cout << e;
        std::cout << std::endl;
    }
}
