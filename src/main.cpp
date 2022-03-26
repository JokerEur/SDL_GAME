#include <SDL2/SDL.h>
#include <iostream>

#include "RenderWindow.hpp"

int main(int argc, char const *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
    {
        std::cout << "SDL_Init FAILED. SDL_ERROR: " << SDL_GetError()
                  << '\n';
    }

    RenderWindow window("Game Test", 1280, 720);

    bool gameRunning{true};

    SDL_Event event;

    while (gameRunning)
    {
        while (SDL_PollEvent(&event))
        {
            
            if (event.type == SDL_QUIT)
            {
                gameRunning = false;
            }
        }
    }

    window.CleanUp();
    SDL_Quit();

    return 0;
}
