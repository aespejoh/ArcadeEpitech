/*
** EPITECH PROJECT, 2021
** globalProject
** File description:
** Created by aespejo,
*/
#include "player.hpp"

int Player::getDirection() const
{
    return _direction;
}

void Player::setDirection(int direction)
{
    _direction = direction;
}

int Player::getX() const
{
    return _x;
}

int Player::getY() const
{
    return _y;
}

void Player::setPosition(int y, int x)
{
    _y = y;
    _x = x;
}

void Player::move()
{
    map_t map;
    map.insert(std::make_pair(UP, &Player::moveUP));
    map.insert(std::make_pair(DOWN, &Player::moveDOWN));
    map.insert(std::make_pair(LEFT, &Player::moveLEFT));
    map.insert(std::make_pair(RIGHT, &Player::moveRIGHT));
    auto it = map.find(_direction);
    if (it == map.end())
        exit(84);
    (this->*it->second)();
}

void Player::moveUP()
{
    _y--;
}

void Player::moveDOWN()
{
    _y++;
}

void Player::moveLEFT()
{
    _x--;
}

void Player::moveRIGHT()
{
    _x++;
}

