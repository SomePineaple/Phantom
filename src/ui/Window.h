//
// Created by somepineaple on 1/30/22.
//

#ifndef PHANTOM_WINDOW_H
#define PHANTOM_WINDOW_H

#include <vector>
#include <SDL.h>
#include "../cheats/Cheat.h"

class Window {
public:
    Window(int width, int height, const char *title);
    void setup();
    void destruct();
    void update(const std::vector<Cheat*>& cheats, bool &running, bool inGame);
private:
    int width, height;
    const char *title;

    SDL_Window *window;
    SDL_GLContext glContext;

    static void drawHelper(const char *desc);
};


#endif //PHANTOM_WINDOW_H
