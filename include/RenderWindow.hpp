#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

#define RESOLUTION_WIGTH 1240
#define RESOLUTION_HIGHT 600

class RenderWindow
{
private:
    SDL_Window *window{NULL};
    SDL_Renderer *renderer{NULL};
    bool windowIsActive{true};

public:
    RenderWindow() = default;
    RenderWindow(const char *p_title, int p_w, int p_h);

    SDL_Texture *loadTexture(const char *p_filePath);
    void Create(const char *p_title, int p_w, int p_h);

    void CleanUp();
    void clear();

    void render(SDL_Texture *p_texture);
    void render(float p_x, float p_y, SDL_Texture *p_tex);
    void renderCenter(float p_x, float p_y, const char *p_text, TTF_Font *font, SDL_Color textColor);

    void display();
    bool getWindowState() { return windowIsActive; };
    void setWindowState(bool p_state) { this->windowIsActive = p_state; };
};
