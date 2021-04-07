/*
** EPITECH PROJECT, 2021
** globalProject
** File description:
** Created by aespejo,
*/
#ifndef GLOBALPROJECT_IDISPLAYMODULE_HPP
#define GLOBALPROJECT_IDISPLAYMODULE_HPP

#include "inputs.h"
#include <iostream>

class IDisplayModule {

    public:
        virtual void init()=0;
        virtual void stop()=0;
        virtual const std::string &getName() const = 0;
        virtual ~IDisplayModule() = default;
        virtual bool isActive() = 0;
        virtual void refresh() = 0;
        virtual char getInput() = 0;
        virtual void printLevel(char **array, unsigned int height, unsigned int width) = 0;

        virtual void initMenu() = 0;
        virtual void initWindow() = 0;
        virtual bool getQuit() = 0;
    protected:
        std::string _name;
        bool _quit = false;
};

#endif //GLOBALPROJECT_IDISPLAYMODULE_HPP
