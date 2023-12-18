#include "pText.h"

namespace pText{
    SDL_Texture* textToTexture(const char* text, TTF_Font* font, const SDL_Color textColor, SDL_Renderer* rend){
        SDL_Surface* tempSurface = TTF_RenderText_Blended(font, text, textColor);
        if(!tempSurface)
            std::cout << SDL_GetError() << std::endl;

        SDL_Texture* tempTexture = SDL_CreateTextureFromSurface(rend, tempSurface);
        if(!tempTexture)
            std::cout << SDL_GetError() << std::endl;
        
        SDL_FreeSurface(tempSurface);
        return tempTexture;
    }

    void getFontSize(const char* text, TTF_Font* font, int* width, int* height){
        TTF_SizeText(font, text, width, height);
    }
}