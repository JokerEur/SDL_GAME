#include "TextureManager.hpp"

SDL_Texture *TextureManager::loadTexture(const std::string path)
{

    SDL_Surface *tmpSurface = IMG_Load(path.c_str());
    SDL_Texture *texture = SDL_CreateTextureFromSurface(Window::renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);

    return texture;
}
void TextureManager::Draw(SDL_Texture *tex , SDL_Rect src, SDL_Rect dest){
    SDL_RenderCopy(Window::renderer, tex, &src,&dest);
}