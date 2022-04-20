#include "TextureManager.hpp"

SDL_Texture *Core::TextureManager::loadTexture(const std::string path)
{

    SDL_Surface *tmpSurface = IMG_Load(path.c_str());
    SDL_Texture *texture = SDL_CreateTextureFromSurface(Core::Window::renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);

    return texture;
}