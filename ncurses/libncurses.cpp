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
    erase();
    printw("Welcome to NCurses!");
    noecho();
    keypad(stdscr, TRUE);
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
    for (auto pixel : array) {
        for (auto i : pixel) {
            std::cout << i << std::endl;
        }
    }
}

void Libncurses::initMenu() {

}

bool Libncurses::getQuit() {
    return _quit;
}