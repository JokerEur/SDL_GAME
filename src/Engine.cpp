#include "Engine.hpp"

Engine::Engine()
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();

    this->font24 = TTF_OpenFont("/home/ivan/Documents/workspace/WinterForest/assets/ttf/cocogoose.ttf", 24);
    this->logo = window.loadTexture("/home/ivan/Documents/workspace/WinterForest/assets/sprite/logo.png");
    



    window.Create("Game v.0.1", 1280, 720);
}

void Engine::run()
{
    // SDL_Texture* logo{window.loadTexture("/home/ivan/Documents/workspace/WinterForest/assets/sprite/cube.png")};
    while (window.getWindowState())
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                window.setWindowState(false);
        }

        window.clear();
        window.render(RESOLUTION_WIGTH/2 - 234, RESOLUTION_HIGHT/2 - 94 - 30, logo);
        window.renderCenter(0, 90 + sinf(SDL_GetTicks()/100) * 2.5f, "Click to start", font24, white);
        window.display();
    }

    window.CleanUp();
	TTF_CloseFont(this->font24);
	TTF_Quit();
	SDL_Quit();
}
