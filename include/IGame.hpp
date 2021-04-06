/*
** EPITECH PROJECT, 2021
** globalProject
** File description:
** Created by aespejo,
*/
#ifndef GLOBALPROJECT_IGAME_HPP
#define GLOBALPROJECT_IGAME_HPP

#include <vector>
#include <player.hpp>

typedef std::vector<std::vector<char>> array_t;

class IGame {
    public:
        virtual ~IGame() = default;
        virtual void loadMap() = 0;
        virtual array_t getArray() {return _array;};
        virtual void put(unsigned int y, unsigned int x, char item) = 0;
        virtual Player* getPlayer() {return player;};
    protected:
        array_t _array;
        Player *player;
};

#endif //GLOBALPROJECT_IGAME_HPP
