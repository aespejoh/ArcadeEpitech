#ifndef LIB2_LIBRARY_H
#define LIB2_LIBRARY_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
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
    char getInput(bool) override;
    void printLevel(array_t array, unsigned int height, unsigned int width
    ) override;
    void initMenu() override;
    bool getQuit() override;
    char manageKey();
    int getEvent() override;
    char getUsername() override;

private:
    void init() override;
    void stop() override;
    const std::string &getName() const override;
    SDL_Window* _window;
    SDL_Event _event;
    SDL_Renderer *_render;
    map_t _block_type;
    TTF_Font *_font;
    TTF_Font *_font_two;
    SDL_Rect _rect;
    SDL_Surface *_text;
    SDL_Surface	*_image;
    SDL_Texture *_texture_image;
    SDL_Texture *_texture_text;
    int _xMouse;
    int _yMouse;
    void displayRedSquare(int, int);
    void displayWhiteSquare(int, int);
    void displayBlackSquare(int, int);
};

#endif //LIB2_LIBRARY_H
