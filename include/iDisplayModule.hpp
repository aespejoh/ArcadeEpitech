/*
** EPITECH PROJECT, 2021
** globalProject
** File description:
** Created by aespejo,
*/
#ifndef GLOBALPROJECT_IDISPLAYMODULE_HPP
#define GLOBALPROJECT_IDISPLAYMODULE_HPP

#include <iostream>

class IDisplayModule {

    public:
        virtual void init()=0;
        virtual void stop()=0;
        virtual const std::string &getName() const = 0;
        virtual ~IDisplayModule() = default;

    protected:
        std::string _name;

};

#endif //GLOBALPROJECT_IDISPLAYMODULE_HPP
