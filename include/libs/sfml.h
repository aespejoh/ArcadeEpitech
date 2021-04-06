/*
** EPITECH PROJECT, 2021
** globalProject
** File description:
** Created by aespejo,
*/
#ifndef GLOBALPROJECT_SFML_H
#define GLOBALPROJECT_SFML_H

#include "SFML/Graphics.hpp"
#include "iDisplayModule.hpp"

class LibSFML : public IDisplayModule {
    public:
        LibSFML() = default;;
        ~LibSFML() override = default;;

    bool isActive() override;

    void refresh() override;

    char getInput() override;

    void printLevel(char **array, unsigned int height, unsigned int width
    ) override;

    private:
    void init() override;
    void stop() override;
    const std::string &getName() const override;
};

#endif //GLOBALPROJECT_SFML_H
