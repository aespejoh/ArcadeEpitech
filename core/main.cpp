#include <iostream>
#include <core.h>

int main()
{
    int i;
    Core core;
    core.loadlib("./lib/libsfml.so");
    core.loadlib("./lib/libsdl.so");
    core.loadlib("./lib/libncurses.so");
    std::cin >> i;
    core.getLibs()[i++]->init();
    return 0;
}
