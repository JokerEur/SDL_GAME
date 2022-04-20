#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>

#include "TextureManager.hpp"
#include "GameObject.hpp"

namespace Core
{

    class Window final
    {
    private:
        std::string name;
        int wight, hight;
        SDL_Window *window = nullptr;

        bool isRunnig;

    public:
        Window(const Window &) = delete;
        Window &operator=(const Window &) = delete;

    private:
        Window(const std::string &name, int wight, int hight);

    private:
        ~Window();

    public:
        static Window &getInstance()
        {
            static Window instance("Window", 1280, 720);
            return instance;
        };

    public:
        static SDL_Renderer *renderer;

        void init(const std::string &name, int wight, int hight);
        void handleEvent();
        void render();
        void update();
        inline bool runnig() { return isRunnig; }
        inline SDL_Window *getSDLwindow() const { return window; }
    };
}
