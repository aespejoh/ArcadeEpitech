#ifndef LIB2_LIBRARY_H
#define LIB2_LIBRARY_H

#include <SDL2/SDL.h>
#include <cstdio>
#include "iDisplayModule.hpp"

class LibSDL : public IDisplayModule {
    public:
    LibSDL();
    ~LibSDL() override = default;

    bool isActive() override;

    void refresh() override;

    char getInput() override;

    void printLevel(array_t array, unsigned int height, unsigned int width
    ) override;

    private:
    void init() override;
    void stop() override;
    const std::string &getName() const override;
};

#endif //LIB2_LIBRARY_H
