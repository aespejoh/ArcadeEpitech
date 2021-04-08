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
    keypad(stdscr, TRUE);
    refresh();
    curs_set(0);
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
    if (ch == KEY_UP) {
        printw("KEYYYY UPOOOO");
        return KEYUP;
    }
    if (ch == KEY_DOWN) {
        printw("KEYYYY DOWNNNOOO");
        return KEYDOWN;
    }
}

void Libncurses::printLevel(array_t array, unsigned int height,
    unsigned int width
)
{
}

void Libncurses::initMenu() {

}

bool Libncurses::getQuit() {
    return _quit;
}