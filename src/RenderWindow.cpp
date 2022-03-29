#include "RenderWindow.hpp"

RenderWindow::RenderWindow(const char *p_title, int p_w, int p_h) : window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);

    if (window == NULL)
    {
        std::cout << " window failed to init. Error: " << SDL_GetError()
                  << '\n';
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void RenderWindow::Create(const char *p_title, int p_w, int p_h)
{
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        std::cout << " window failed to init. Error: " << SDL_GetError()
                  << '\n';
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture *RenderWindow::loadTexture(const char *p_filePath)
{
    SDL_Texture *texture{nullptr};
    texture = IMG_LoadTexture(renderer, p_filePath);

    if (texture == NULL)
    {
        std::cout << "Failed to load texture. Error: " << SDL_GetError()
                  << '\n';
    }

    return texture;
}

void RenderWindow::CleanUp()
{
    SDL_DestroyWindow(window);
}

void RenderWindow::clear()
{
    SDL_SetRenderDrawColor(renderer, 90, 90, 90, 255);
    SDL_RenderClear(renderer);
}

void RenderWindow::display()
{   
    SDL_RenderPresent(renderer);
}

void RenderWindow::render(float p_x, float p_y, SDL_Texture *p_tex)
{
    SDL_RenderClear(renderer);
    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    SDL_QueryTexture(p_tex, NULL, NULL, &src.w, &src.h);

    SDL_Rect dst;
    dst.x = p_x;
    dst.y = p_y;
    dst.w = src.w;
    dst.h = src.h;

    SDL_RenderCopy(renderer, p_tex, &src, &dst);
}

void RenderWindow::render(SDL_Texture *p_tex)
{
    SDL_RenderClear(renderer);
    render(0, 0, p_tex);
}

void RenderWindow::renderCenter(float p_x, float p_y, const char *p_text, TTF_Font *font, SDL_Color textColor)
{
    SDL_RenderClear(renderer);
    SDL_Surface *surfaceMessage = TTF_RenderText_Blended(font, p_text, textColor);
    SDL_Texture *message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w =surfaceMessage->w;
    src.h =surfaceMessage->h;


    SDL_Rect dst;
    dst.x = RESOLUTION_WIGTH / 2 - src.w / 2 + p_x;
    dst.y = RESOLUTION_HIGHT/ 2 - src.h / 2 + p_y;
    dst.w = src.w;
    dst.h = src.h;

    SDL_RenderCopy(renderer, message, &src, &dst);
    SDL_FreeSurface(surfaceMessage);
}
