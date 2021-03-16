#include <iostream>
#include <core.h>

int main()
{
    int i;
    Core core;
    core.loadlib("./lib/arcade_sfml.so");
    core.loadlib("./lib/arcade_sdl2.so");
    core.loadlib("./lib/arcade_ncurses.so");
    std::cin >> i;
    core.getLibs()[i++]->init();
    return 0;
}
