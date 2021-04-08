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

void Libncurses::init()
{
    initscr();
    printw("Welcome to NCurses!");
    noecho();
    refresh();
    endwin();
}

void Libncurses::stop()
{
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

    if (ch == KEY_RIGHT)
        printw("KEY RIGHTHTHTHT");
    if (ch == KEY_LEFT)
        printw("KEY LEFTTTT");
}

void Libncurses::printLevel(array_t array, unsigned int height,
    unsigned int width
)
{
}

void Libncurses::initMenu() {

}

void Libncurses::initWindow() {

}

bool Libncurses::getQuit() {
    return _quit;
}