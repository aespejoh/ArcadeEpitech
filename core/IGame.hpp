/*
** EPITECH PROJECT, 2021
** globalProject
** File description:
** Created by aespejo,
*/
#ifndef GLOBALPROJECT_IGAME_HPP
#define GLOBALPROJECT_IGAME_HPP

class IGame {
    public:
        virtual ~IGame() = 0;
        virtual void loadMap() = 0;
    protected:

};

#endif //GLOBALPROJECT_IGAME_HPP
