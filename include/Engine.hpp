#pragma once
#include "RenderWindow.hpp"
#include <vector>
#include <cmath>

const unsigned int FPS{60};
const unsigned int frameDelay{1000/FPS};

class Engine
{
private:
    RenderWindow window;
    SDL_Event event;
    TTF_Font* font24{nullptr};
    SDL_Texture* logo;
    SDL_Color white{255,255,255};

    int currentGameState;
    int lastGameState;

public:
    enum GameState
    {
        MENU,
        RUNNING,
        PAUSED,
        GAMEOVER
    };
    Engine();
    void run();
};
