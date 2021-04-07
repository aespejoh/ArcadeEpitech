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

#define SQUARE_SIZE 25, 25

extern "C" IDisplayModule* create()
{
    return new LibSDL();
}

void LibSDL::init()
{
    SDL_Window* window = nullptr;
    SDL_Surface* screenSurface = nullptr;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    else {
        //Create window
        window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == nullptr )
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        else {
            //Get window surface
            screenSurface = SDL_GetWindowSurface( window );
            //Fill the surface white
            SDL_FillRect( screenSurface, nullptr, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
            //Update the surface
            SDL_UpdateWindowSurface( window );
            //Wait two seconds
            SDL_Delay( 2000 );
        }
    }
    //Destroy window
    SDL_DestroyWindow( window );
    //Quit SDL subsystems
    SDL_Quit();
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
    while (SDL_PollEvent(&_event) != 0) {
        if (_event.type == SDL_QUIT) {
            stop();
            _quit = true;
        }
        if (_event.type == SDL_KEYUP)
            return KEYUP;
        if (_event.type == SDL_KEYDOWN)
            return KEYDOWN;
    }
}

void LibSDL::printLevel(char **array, unsigned int height, unsigned int width)
{
}

void LibSDL::initMenu()
{
    SDL_SetRenderDrawColor(_render, BLACK);
    SDL_RenderClear(_render);
    displayRedSquare(SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4);
    SDL_RenderPresent(_render);
}

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

bool LibSDL::getQuit() {
    return _quit;
}

void LibSDL::stop()
{
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void LibSDL::displayRedSquare(int x, int y)
{
    SDL_Rect fillRect = {x, y, SQUARE_SIZE};
    SDL_SetRenderDrawColor(_render, RED);
    SDL_RenderFillRect(_render, &fillRect);
}

