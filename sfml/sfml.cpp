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
    _window = new sf::RenderWindow(sf::VideoMode(1000, 1000), "");
}

void LibSFML::stop()
{
    _window->close();
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
    _window->display();
}

char LibSFML::getInput(bool input)
{
    sf::Event event{};
    while (_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            _window->close();
            _quit = false;
            return '\0';
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up)
                return KEYUP;
            if (event.key.code == sf::Keyboard::Down)
                return KEYDOWN;
            if (event.key.code == sf::Keyboard::W)
                return 'w';
            if (event.key.code == sf::Keyboard::S)
                return 's';
            if (event.key.code == sf::Keyboard::A)
                return 'a';
            if (event.key.code == sf::Keyboard::D)
                return 'd';
        }
    }
}

void LibSFML::printLevel(array_t array, unsigned int height, unsigned int width)
{
    _window->clear();
    _block_type.insert(std::make_pair('7', &LibSFML::drawBlackSquare));
    _block_type.insert(std::make_pair('0', &LibSFML::drawWhiteSquare));
    _block_type.insert(std::make_pair('1', &LibSFML::drawWhiteSquare));
    _block_type.insert(std::make_pair('2', &LibSFML::drawWhiteSquare));
    _block_type.insert(std::make_pair('3', &LibSFML::drawWhiteSquare));
    _block_type.insert(std::make_pair('4', &LibSFML::drawWhiteSquare));
    _block_type.insert(std::make_pair('5', &LibSFML::drawWhiteSquare));
    _block_type.insert(std::make_pair('A', &LibSFML::drawRedSquare));
    _block_type.insert(std::make_pair('8', &LibSFML::drawBlueCircle));
    int x = 0;
    int y = 0;
    for (auto &i: array) {
        for (auto &e : i) {
            auto it = _block_type.find(e);
            if (it == _block_type.end())
                continue;
            (this->*it->second)(x, y);
            x += 10;
        }
        x = 0;
        y += 10;
    }
}

LibSFML::LibSFML()
{
    _name = "sfml";
    _window = nullptr;
}

void LibSFML::drawBlackSquare(int x, int y)
{
    sf::RectangleShape cell;
    cell.setSize(sf::Vector2f(10,10));
    cell.setFillColor(sf::Color::Black);
    cell.setPosition(x, y);
    _window->draw(cell);
}

void LibSFML::drawWhiteSquare(int x, int y)
{
    sf::RectangleShape cell;
    cell.setSize(sf::Vector2f(10,10));
    cell.setFillColor(sf::Color::White);
    cell.setPosition(x, y);
    _window->draw(cell);
}

void LibSFML::drawRedSquare(int x, int y)
{
    sf::RectangleShape cell;
    cell.setSize(sf::Vector2f(10,10));
    cell.setFillColor(sf::Color::Red);
    cell.setPosition(x, y);
    _window->draw(cell);
}

void LibSFML::drawBlueCircle(int x, int y)
{
    sf::CircleShape cell;
    cell.setRadius(5);
    cell.setFillColor(sf::Color::Blue);
    cell.setPosition(x, y);
    _window->draw(cell);
}

void LibSFML::initMenu()
{
}

bool LibSFML::getQuit()
{
    return _quit;
}

int LibSFML::getEvent() {
    return 0;
}

std::string LibSFML::getUsername() {
    return std::string();
}

void LibSFML::printInfo(std::string, std::string, std::string) {

}
