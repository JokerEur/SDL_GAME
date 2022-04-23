#pragma once

#include "Components.hpp"
#include <SDL.h>

class SpriteComponent : public Component
{
private:
    PositionComponent *position;
    SDL_Texture *texture;
    SDL_Rect srcRect, destRect;

public:
    SpriteComponent() = default;
    SpriteComponent(const std::string path)
    {
        texture = TextureManager::loadTexture(path);
    }

    void init() override
    {

        position = &entity->getComponent<PositionComponent>();

        srcRect.x = 0;
        srcRect.y = 0;
        srcRect.w = 32;
        srcRect.h = 32;

        destRect.w = 64;
        destRect.h = 64;
    }

    void update() override
    {
        destRect.x = position->x();
        destRect.y = position->y();
    }

    void draw() override
    {
        TextureManager::Draw(texture, srcRect, destRect);
    }
};