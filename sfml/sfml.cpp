/*
** EPITECH PROJECT, 2021
** globalProject
** File description:
** Created by aespejo,
*/

#include "libs/sfml.h"

extern "C" IDisplayModule* create()
{
    return new LibSFML();
}

void LibSFML::init()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();
        window.clear();
        window.draw(shape);
        window.display();
    }
}

void LibSFML::stop()
{
}

const std::string &LibSFML::getName() const
{
    return _name;
}

bool LibSFML::isActive()
{
    return false;
}

void LibSFML::refresh()
{
}

char LibSFML::getInput()
{
    return 0;
}

void LibSFML::printLevel(char **array, unsigned int height, unsigned int width)
{
}

void LibSFML::initMenu() {

}

void LibSFML::initWindow() {

}

bool LibSFML::getQuit() {
    return false;
}
