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
    createMap(10,10);
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

void SnakeGame::update(char input)
{
    auto it = movement_Input.find(input);
    if (it != movement_Input.end()) {
        std::cout << input << std::endl;
        put(getPlayer()->getY(), getPlayer()->getX(), EMPTY_SPACE);
        getPlayer()->setDirection(it->second);
        getPlayer()->move();
        put(getPlayer()->getY(), getPlayer()->getX(), HEAD);
        printMap();
    }
}

SnakeGame::SnakeGame()
{
    _player = new Player;
    movement_Input.insert(std::make_pair('w', 1));
    movement_Input.insert(std::make_pair('a', 3));
    movement_Input.insert(std::make_pair('s', 2));
    movement_Input.insert(std::make_pair('d', 4));
}