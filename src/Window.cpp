#include "Window.hpp"
#include "TextureManager.hpp"
#include "ECS/Components.hpp"

SDL_Renderer *Window::renderer = nullptr;
Manager manager;

auto &player(manager.addEntity());

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

    player.addComponent<PositionComponent>();
    //player.addComponent<SpriteComponent>("/home/ivan/Documents/workspace/WinterForest/assets/sprite/logo.png");
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

void Window::update()
{
   manager.refresh();
   manager.update();
}

void Window::render()
{
    SDL_RenderClear(renderer);
    manager.draw();
    SDL_RenderPresent(renderer);
}


Window::~Window()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
