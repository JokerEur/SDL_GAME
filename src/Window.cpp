#include "Window.hpp"

#include "ECS.hpp"
#include "Components.hpp"

namespace Core
{
    Manager manager;
    auto& newPlayer(manager.addEntity());
    GameObject *player;
    SDL_Renderer *Window::renderer = nullptr;

    Window::Window(const std::string &name, int wight, int hight)
    {
        init(name, wight, hight);
    }

    void Window::init(const std::string &name, int wight, int hight)
    {

        IMG_Init(IMG_INIT_PNG);

        if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
        {

            window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, wight, hight, SDL_WINDOW_SHOWN);

            if (!window)
            {
                std::cout << " window failed to init. Error: " << SDL_GetError()
                          << '\n';
            }

            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

            if (renderer)
            {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            }
            isRunnig = true;
        }
        player = new GameObject("/home/ivan/Documents/workspace/WinterForest/assets/sprite/logo.png", 0, 0);
        
    }

    void Window::render()
    {
        SDL_RenderClear(renderer);
        player->Render();
        SDL_RenderPresent(renderer);
    }

    void Window::update()
    {
        player->Update();
    }

    void Window::handleEvent()
    {
        SDL_Event event;
        SDL_PollEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            isRunnig = false;
            break;

        default:
            break;
        }
    }

    Window::~Window()
    {
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        SDL_Quit();
    }

}
