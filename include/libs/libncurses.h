#ifndef LIB1_LIBRARY_H
#define LIB1_LIBRARY_H

#include <ncurses.h>
#include "iDisplayModule.hpp"

void hello();

class Libncurses : public IDisplayModule {
    public:
    Libncurses() = default;
    ~Libncurses() override = default;

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
};


#endif //LIB1_LIBRARY_H
