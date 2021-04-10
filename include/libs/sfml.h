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
#include "inputs.h"

class LibSFML : public IDisplayModule {
    typedef void (LibSFML::*fnc_ptr)(int x, int y);
    typedef std::map<char, fnc_ptr> map_t;
    public:
        LibSFML();
        ~LibSFML() override = default;
        bool isActive() override;
        void refresh() override;
        char getInput() override;
        void printLevel(array_t array, unsigned int height, unsigned int width
        ) override;
        void initMenu() override;
        bool getQuit() override;
    private:
        void init() override;
        void stop() override;
        const std::string &getName() const override;
        sf::RenderWindow *_window;
        map_t _block_type;
        void drawBlackSquare(int x, int y);
        void drawWhiteSquare(int x, int y);
        void drawRedSquare(int x, int y);
        void drawBlueCircle(int x, int y);
    //void init(const array_t& array);
};

#endif //GLOBALPROJECT_SFML_H
