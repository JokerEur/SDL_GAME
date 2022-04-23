#include "GameObject.hpp"

GameObject::GameObject(const std::string texturesheet, int x, int y)
{
    ObjTexture = TextureManager::loadTexture(texturesheet);
    x_pos = x;
    y_pos = y;
}

void GameObject::Update()
{

    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;

    dstRect.x = x_pos;
    dstRect.y = y_pos;
    dstRect.w = srcRect.w * 2;
    dstRect.h = srcRect.h * 2;
}

void GameObject::Render()
{
    SDL_RenderCopy(Window::renderer,ObjTexture, &srcRect, &dstRect);
}