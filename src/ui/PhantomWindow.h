//
// Created by somepineaple on 1/30/22.
//

#ifndef PHANTOM_PHANTOMWINDOW_H
#define PHANTOM_PHANTOMWINDOW_H

#include <vector>
#include <SDL.h>
#include "../cheats/Cheat.h"

class PhantomWindow {
public:
    PhantomWindow(int width, int height, const char *title);
    void setup();
    void destruct();
    void update(const std::vector<Cheat*>& cheats, bool &running, bool inGame);
private:
    int width, height;
    const char *title;

    SDL_Window *window;
    SDL_GLContext glContext;
};


#endif //PHANTOM_PHANTOMWINDOW_H
