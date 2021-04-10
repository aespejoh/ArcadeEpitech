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
    array[height / 2][width / 2] = 'A';
    _player->setPosition(height / 2, width / 2);
    _array = array;
    generateFood();
}

void SnakeGame::loadMap()
{
    createMap(width,height);
}

array_t SnakeGame::getArray()
{
    return _array;
}

void SnakeGame::put(unsigned int y, unsigned int x, char item)
{
    try {
        _array[y][x] = item;
    } catch (MainException &exception) {
        return;
    }
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
    _current = clock();
    _time_counter += (double)(_current - _last);
    _last = _current;
    put(getPlayer()->getY(), getPlayer()->getX(), EMPTY_SPACE);
    if (_time_counter > (double)(num_sec * CLOCKS_PER_SEC)) {
        _time_counter -= (double)(num_sec * CLOCKS_PER_SEC);
        if (check_ahead() == IS_WALL) {
            game_over = true;
            return;
        } else if (check_ahead() == IS_FOOD) {
            generateFood();
            _len++;
        }
        getPlayer()->move();
    }
    auto it = movement_Input.find(input);
    if (it != movement_Input.end()) {
        //std::cout << input << std::endl;
        getPlayer()->setDirection(it->second);
        //printMap();
    }
    put(getPlayer()->getY(), getPlayer()->getX(), HEAD);
}

void SnakeGame::SnakeLogic()
{

}

SnakeGame::SnakeGame()
{
    game_over = false;
    _current = clock();
    _last = _current;
    _len = 4;
    _player = new Player;
    movement_Input.insert(std::make_pair('w', 1));
    movement_Input.insert(std::make_pair('a', 3));
    movement_Input.insert(std::make_pair('s', 2));
    movement_Input.insert(std::make_pair('d', 4));
}

int SnakeGame::check_ahead()
{
    int x = getPlayer()->getX();
    int y = getPlayer()->getY();
    switch (getPlayer()->getDirection()) {
    case RIGHT:
        if (SOLID_OBJECT.count(_array[y][x + 1]) != 0) //if next is solid
            return IS_WALL;
        else if (_array[y][x + 1] == FOOD)
            return IS_FOOD;
        return IS_EMPTY;
    case LEFT:
        if (SOLID_OBJECT.count(_array[y][x - 1]) != 0) //if next is solid
            return IS_WALL;
        else if (_array[y][x - 1] == FOOD)
            return IS_FOOD;
        return IS_EMPTY;
    case UP:
        if (SOLID_OBJECT.count(_array[y - 1][x]) != 0) //if next is solid
            return IS_WALL;
        else if (_array[y - 1][x] == FOOD)
            return IS_FOOD;
        return IS_EMPTY;
    case DOWN:
        if (SOLID_OBJECT.count(_array[y + 1][x]) != 0) //if next is solid
            return IS_WALL;
        else if (_array[y + 1][x] == FOOD)
            return IS_FOOD;
        return IS_EMPTY;
    }
}

int SnakeGame::check_pos(int x, int y)
{
    if (SOLID_OBJECT.count(_array[y][x]) != 0) //if next is solid
        return IS_WALL;
    else if (_array[y][x] == FOOD)
        return IS_FOOD;
    return IS_EMPTY;
}

bool SnakeGame::isGameOver() const
{
    return game_over;
}

void SnakeGame::generateFood()
{
    int x = (int)random() % 50;
    int y = (int)random() % 50;
    if (check_pos(x, y) == IS_EMPTY)
        put(y, x, FOOD);
    else
        generateFood();
}