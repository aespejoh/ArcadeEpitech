#include "libs/sdl.h"
#include <iostream>
#include <libncurses.h>

#define RED 255, 0, 0, 0.7
#define GREEN 0, 255, 0, 0.7
#define WHITE 255, 255, 255, 0
#define BLUE 0, 0, 255, 0.8
#define YELLOW 255, 255, 0, 1
#define BLACK 0, 0, 0, 1

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

#define SQUARE_SIZE 10, 10

extern "C" IDisplayModule* create()
{
    return new LibSDL();
}

void LibSDL::init()
{
    _window = nullptr;
    _render = nullptr;

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    else {
        _window = SDL_CreateWindow("SDL Tutorial",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH, SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN);
        if (_window == nullptr) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            SDL_Quit();
        } else {
            _render = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
            if (_render == nullptr) {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                SDL_Quit();
            }
        }
    }
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

char LibSDL::getInput()
{
    while( SDL_PollEvent(&_event)){
        if(_event.type == SDL_QUIT) {
            stop();
            _quit = true;
        } else if(_event.type == SDL_KEYDOWN) {
            switch(_event.key.keysym.sym) {
                case SDLK_UP:
                    std::cout << "key up" << std::endl;
                    return KEYUP;
                case SDLK_DOWN:
                    std::cout << "key down" << std::endl;
                    return KEYDOWN;
                case SDLK_LEFT:
                    std::cout << "key left" << std::endl;
                    return KEYDOWN;
                case SDLK_RIGHT:
                    std::cout << "key right" << std::endl;
                    return KEYDOWN;
                default:
                    std::cout << "key up" << std::endl;
                    return KEYDOWN;
            }
        }
    }
}

void LibSDL::initMenu()
{
    SDL_SetRenderDrawColor(_render, BLACK);
    SDL_RenderClear(_render);
    displayRedSquare(SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4);
    SDL_RenderPresent(_render);
}

/*
void LibSDL::initWindow() {
    _window = nullptr;
    _render = nullptr;

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    else {
        _window = SDL_CreateWindow("SDL Tutorial",
                                   SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                   SCREEN_WIDTH, SCREEN_HEIGHT,
                                   SDL_WINDOW_SHOWN);
        if (_window == nullptr) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            SDL_Quit();
        } else {
            _render = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
            if (_render == nullptr) {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                SDL_Quit();
            }
        }
    }
}
*/

bool LibSDL::getQuit() {
    return _quit;
}

void LibSDL::stop()
{
    SDL_DestroyWindow(_window);
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

