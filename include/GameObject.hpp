#pragma once
#include "Window.hpp"
#include "TextureManager.hpp"

namespace Core
{

    class GameObject
    {
    private:
        int x_pos, y_pos;
        SDL_Texture *ObjTexture;
        SDL_Rect srcRect, dstRect;

    public:
        GameObject(const std::string texturesheet,int x , int y);
        ~GameObject();
    public:

        void Render();
        void Update();
    };
    
}
