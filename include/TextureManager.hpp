#pragma once
#include "Window.hpp"

namespace Core
{
    class TextureManager
    {
    public:
        static SDL_Texture *loadTexture(const std::string name);
    private:
    };

}