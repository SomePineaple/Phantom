//
// Created by somepineaple on 1/30/22.
//

#ifndef MC_INJECTION_WINDOW_H
#define MC_INJECTION_WINDOW_H

#include <SDL.h>
#include "../cheats/AimBot.h"

class Window {
public:
    Window(int width, int height, const char *title);
    void setup();
    void destruct();
    void update(AimBot *aim, bool &running, bool inGame);
private:
    int width, height;
    const char *title;

    SDL_Window *window;
    SDL_GLContext glContext;

    static void drawHelper(const char *desc);
};


#endif //MC_INJECTION_WINDOW_H
