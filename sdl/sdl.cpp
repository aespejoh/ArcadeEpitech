#include "libs/sdl.h"
#include <iostream>
#include <libncurses.h>

#define RED 255, 0, 0, 0.7
#define COLOR 104, 227, 165, 0.9
#define GREEN 0, 255, 0, 0.7
#define WHITE 255, 255, 255, 0
#define BLUE 0, 0, 255, 0.8
#define YELLOW 255, 255, 0, 1
#define BLACK 0, 0, 0, 1
#define CYAN 124, 196, 196, 1

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 750;

#define SQUARE_SIZE 10, 10

extern "C" IDisplayModule* create()
{
    return new LibSDL();
}

void LibSDL::init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
        _quit = true;
    TTF_Init();
    _window = SDL_CreateWindow("arcade",
                                           SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                           SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    _render = SDL_CreateRenderer(_window, -1, 0);
    SDL_SetRenderDrawColor(_render, WHITE);
    _image = IMG_Load("./resources/images/b4638aa66c9882cbb725d1adf0fed6b0.jpg");
    _font = TTF_OpenFont("./OpenSans-Bold.ttf", 50);
    _font_two = TTF_OpenFont("./OpenSans-Bold.ttf", 25);
    _texture_image = SDL_CreateTextureFromSurface(_render, _image);
}

const std::string &LibSDL::getName() const
{
    return _name;
}

bool LibSDL::isActive()
{
    return false;
}

void LibSDL::refresh()
{
}

char LibSDL::manageKeyFalse()
{
    switch (_event.key.keysym.sym) {
        case SDLK_UP:
            return KEYUP;
        case SDLK_DOWN:
            return KEYDOWN;
        case SDLK_BACKSPACE:
            if (_username.length() > 0)
                _username.pop_back();
            break;
        case SDLK_a:
            return 'a';
        case SDLK_w:
            return 'w';
        case SDLK_s:
            return 's';
        case SDLK_d:
            return 'd';
    }
}

char LibSDL::manageKeyTrue()
{
    switch (_event.key.keysym.sym) {
        case SDLK_UP:
            return KEYUP;
        case SDLK_DOWN:
            return KEYDOWN;
        case SDLK_BACKSPACE:
            if (_username.length() > 0)
                _username.pop_back();
            return BACKSPACE;
    }
}

char LibSDL::getInput(bool input)
{
    while( SDL_PollEvent(&_event)){
        switch (_event.type) {
            case SDL_QUIT:
                stop();
                _quit = true;
                break;
            case SDL_TEXTINPUT:
                _username += (static_cast<char>(*_event.text.text));
                break;
            case SDL_KEYDOWN:
                if (input)
                    return manageKeyTrue();
                else
                    return manageKeyFalse();
            case SDL_MOUSEBUTTONDOWN:
                if(_event.button.button == SDL_BUTTON_LEFT){
                    SDL_GetMouseState(&_xMouse,&_yMouse);
                    if (_xMouse >= 400 && _xMouse <= 600 && _yMouse >= 550 && _yMouse <= 650 && input == true) {
                        return MOUSELEFT;
                    }
                }
                return 0;
        }
    }
}

void LibSDL::initMenu()
{
    SDL_Color white = { 255, 255, 255 };
    SDL_RenderCopy(_render, _texture_image, nullptr, nullptr);
    _rect = { 350, 50, 300, 100 };
    _text = TTF_RenderText_Solid(_font, "ARCADE", white);
    _texture_text = SDL_CreateTextureFromSurface(_render, _text);
    SDL_RenderCopy(_render, _texture_text, nullptr, &_rect);
    _rect = { 400, 550, 200, 100 };
    _text = TTF_RenderText_Solid(_font, "Play", white);
    _texture_text = SDL_CreateTextureFromSurface(_render, _text);
    SDL_RenderCopy(_render, _texture_text, nullptr, &_rect);
    _rect = { 150, 200, 225, 50 };
    _text = TTF_RenderText_Solid(_font_two, "Username:", white);
    _texture_text = SDL_CreateTextureFromSurface(_render, _text);
    SDL_RenderCopy(_render, _texture_text, nullptr, &_rect);
    _rect = { 150, 300, 125, 50 };
    _text = TTF_RenderText_Solid(_font_two, "Game:", white);
    _texture_text = SDL_CreateTextureFromSurface(_render, _text);
    SDL_RenderCopy(_render, _texture_text, nullptr, &_rect);
    _rect = { 150, 400, 125, 50 };
    _text = TTF_RenderText_Solid(_font_two, "Lib:", white);
    _texture_text = SDL_CreateTextureFromSurface(_render, _text);
    SDL_RenderCopy(_render, _texture_text, nullptr, &_rect);
    _rect = { 50, 500, 250, 50 };
    _text = TTF_RenderText_Solid(_font_two, "Key Up -> Next Lib", white);
    _texture_text = SDL_CreateTextureFromSurface(_render, _text);
    SDL_RenderCopy(_render, _texture_text, nullptr, &_rect);
    _rect = { 50, 550, 300, 50 };
    _text = TTF_RenderText_Solid(_font_two, "Key Down -> Prev Lib", white);
    _texture_text = SDL_CreateTextureFromSurface(_render, _text);
    SDL_RenderCopy(_render, _texture_text, nullptr, &_rect);
}

void LibSDL::printInfo(std::string username, std::string lib, std::string game)
{
    SDL_Color white = { 255, 255, 255 };
    _rect = { 600, 200, static_cast<int>((username.length() * 25)), 50 };
    _text = TTF_RenderText_Solid(_font_two, username.c_str(), white);
    _texture_text = SDL_CreateTextureFromSurface(_render, _text);
    SDL_RenderCopy(_render, _texture_text, nullptr, &_rect);
    _rect = { 600, 400, 125, 50 };
    _text = TTF_RenderText_Solid(_font_two, lib.c_str(), white);
    _texture_text = SDL_CreateTextureFromSurface(_render, _text);
    SDL_RenderCopy(_render, _texture_text, nullptr, &_rect);
    _rect = { 600, 300, 125, 50 };
    _text = TTF_RenderText_Solid(_font_two, game.c_str(), white);
    _texture_text = SDL_CreateTextureFromSurface(_render, _text);
    SDL_RenderCopy(_render, _texture_text, nullptr, &_rect);
    SDL_RenderPresent(_render);
}

bool LibSDL::getQuit() {
    return _quit;
}

void LibSDL::stop()
{
    SDL_DestroyWindow(_window);
    TTF_Quit();
    SDL_Quit();
}

void LibSDL::displayBlackSquare(int x, int y)
{
    SDL_Rect fillRect = {x, y, SQUARE_SIZE};
    SDL_SetRenderDrawColor(_render, BLACK);
    SDL_RenderFillRect(_render, &fillRect);
    SDL_RenderPresent(_render);
}

void LibSDL::displayWhiteSquare(int x, int y)
{
    SDL_Rect fillRect = {x, y, SQUARE_SIZE};
    SDL_SetRenderDrawColor(_render, WHITE);
    SDL_RenderFillRect(_render, &fillRect);
    SDL_RenderPresent(_render);
}

void LibSDL::displayRedSquare(int x, int y)
{
    SDL_Rect fillRect = {x, y, SQUARE_SIZE};
    SDL_SetRenderDrawColor(_render, RED);
    SDL_RenderFillRect(_render, &fillRect);
    SDL_RenderPresent(_render);
}

void LibSDL::printLevel(array_t array, unsigned int height, unsigned int width)
{
    _block_type.insert(std::make_pair('7', &LibSDL::displayBlackSquare));
    _block_type.insert(std::make_pair('0', &LibSDL::displayWhiteSquare));
    _block_type.insert(std::make_pair('1', &LibSDL::displayWhiteSquare));
    _block_type.insert(std::make_pair('2', &LibSDL::displayWhiteSquare));
    _block_type.insert(std::make_pair('3', &LibSDL::displayWhiteSquare));
    _block_type.insert(std::make_pair('4', &LibSDL::displayWhiteSquare));
    _block_type.insert(std::make_pair('5', &LibSDL::displayWhiteSquare));
    _block_type.insert(std::make_pair('8', &LibSDL::displayRedSquare));
    SDL_SetRenderDrawColor(_render, BLACK);
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

std::string LibSDL::getUsername()
{
    return _username;
}

LibSDL::LibSDL()
{
    _name = "sdl2";
    _window = nullptr;
    _render = nullptr;
}

void LibSDL::clearScreen()
{
    SDL_SetRenderDrawColor(_render, BLACK);
    SDL_RenderClear(_render);
    SDL_RenderPresent(_render);
}
