#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_test_images.h>
#include <iostream>

class RenderWindow
{
private:
    SDL_Window *window;
    SDL_Renderer *render;

public:
    RenderWindow(const char *p_title, int p_w, int p_h);
    void CleanUp();
};
