#ifndef LIB2_LIBRARY_H
#define LIB2_LIBRARY_H

#include <SDL2/SDL.h>
#include <cstdio>
#include <map>
#include "iDisplayModule.hpp"

class LibSDL : public IDisplayModule {
    typedef void (LibSDL::*fnc_ptr)(int, int);
    typedef std::map<char, fnc_ptr> map_t;
    public:
    LibSDL() = default;
    ~LibSDL() override = default;
    bool isActive() override;
    void refresh() override;
    char getInput() override;
    void printLevel(array_t array, unsigned int height, unsigned int width
    ) override;
    void initMenu() override;
    void initWindow() override;
    bool getQuit() override;

    private:
    void init() override;
    void stop() override;
    const std::string &getName() const override;
    SDL_Window* _window;
    SDL_Event _event;
    SDL_Renderer *_render;
    map_t _block_type;
    void displayRedSquare(int, int);
    void displayWhiteSquare(int, int);
    void displayBlackSquare(int, int);
};

#endif //LIB2_LIBRARY_H
