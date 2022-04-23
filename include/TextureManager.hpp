#pragma once
#include "Window.hpp"

    class TextureManager
    {
    public:
        static SDL_Texture *loadTexture(const std::string name);
        static void Draw(SDL_Texture * tex, SDL_Rect src , SDL_Rect dest); 
    private:
    };
