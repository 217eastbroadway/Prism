#include <pRender.h>

namespace pRender{
    SDL_Texture* makeTextureFromImage(SDL_Renderer* renderer, std::string textureDir){
        SDL_Surface* loadSurface = IMG_Load(textureDir.c_str());
        if(!loadSurface)
            std::cout << SDL_GetError() << std::endl;

        SDL_Surface* loadAdvancedSurface = SDL_ConvertSurfaceFormat(loadSurface, SDL_PIXELFORMAT_RGBA32, 0);

        SDL_Texture* returnTexture = SDL_CreateTextureFromSurface(renderer, loadAdvancedSurface);
        if(!returnTexture)
            std::cout << SDL_GetError() << std::endl;

        SDL_FreeSurface(loadSurface);
        SDL_FreeSurface(loadAdvancedSurface);
        return returnTexture;
    }
}