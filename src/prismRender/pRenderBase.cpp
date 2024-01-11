#include <pRender.h>

SDL_Renderer* renderer;
SDL_Window* win;

namespace pRender{
    void copyToRender(SDL_Texture* srcTexture, SDL_Rect *destRectangle){
        SDL_RenderCopy(renderer, srcTexture, NULL, destRectangle);
    }
}