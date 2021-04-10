#include "libncurses.h"

#include <iostream>

extern "C" IDisplayModule* create()
{
    return new Libncurses;
}

extern "C" int destroy()
{
    return 0;
}

Libncurses::Libncurses() {
    displayMap.insert(std::make_pair('A', &Libncurses::printPlayer));
    displayMap.insert(std::make_pair('0', &Libncurses::printWall));
    displayMap.insert(std::make_pair('1', &Libncurses::printWall));
    displayMap.insert(std::make_pair('2', &Libncurses::printWall));
    displayMap.insert(std::make_pair('3', &Libncurses::printWall));
    displayMap.insert(std::make_pair('4', &Libncurses::printWall));
    displayMap.insert(std::make_pair('5', &Libncurses::printWall));
    displayMap.insert(std::make_pair('7', &Libncurses::printBlank));
    displayMap.insert(std::make_pair('8', &Libncurses::printFood));
}

void Libncurses::init()
{
    initscr();
    erase();
    noecho();
    nodelay(stdscr, true);
    keypad(stdscr, true);
    curs_set(0);
}

void Libncurses::stop()
{
    endwin();
}

const std::string &Libncurses::getName() const
{
    return _name;
}

bool Libncurses::isActive()
{
    return false;
}

void Libncurses::refresh()
{
}

char Libncurses::getInput()
{
    int ch = getch();
    if (ch == KEY_UP)
        return KEYUP;
    if (ch == KEY_DOWN)
        return KEYDOWN;
    return ch;
}

void Libncurses::printLevel(array_t array, unsigned int height,
    unsigned int width
)
{
    int f = 0;
    int s = 0;

    for (std::vector<char> line : array) {
        for (char pixel : line) {
            auto it = displayMap.find(pixel);
            if (it == displayMap.end())
                continue;
            (this->*it->second)(s, f);
            f++;
        }
        f = 0;
        s++;
    }
}

void Libncurses::printWall(int x, int y)
{
    mvprintw(x, y, "#");
}

void Libncurses::printBlank(int x, int y)
{
    mvprintw(x, y, " ");
}

void Libncurses::printPlayer(int x, int y)
{
    mvprintw(x, y, "P");
}

void Libncurses::printFood(int x, int y)
{
    mvprintw(x, y, "F");
}

void Libncurses::initMenu() {

}

bool Libncurses::getQuit() {
    return _quit;
}