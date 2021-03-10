#ifndef LIB2_LIBRARY_H
#define LIB2_LIBRARY_H

#include <SDL2/SDL.h>
#include <cstdio>
#include "iDisplayModule.hpp"

class LibSDL : public IDisplayModule {
    public:
    LibSDL() = default;
    ~LibSDL() override = default;

    private:
    void init() override;
    void stop() override;
    const std::string &getName() const override;
};

#endif //LIB2_LIBRARY_H
