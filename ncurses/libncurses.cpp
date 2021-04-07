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
    initscr();			/* Start curses mode 		  */
    printw("Hello World !!!");	/* Print Hello World		  */
    refresh();			/* Print it on to the real screen */
    getch();			/* Wait for user input */
    endwin();			/* End curses mode		  */
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
    return 0;
}

void Libncurses::printLevel(char **array, unsigned int height,
    unsigned int width
)
{
}

void Libncurses::initMenu() {

}

void Libncurses::initWindow() {

}

bool Libncurses::getQuit() {
    return false;
}