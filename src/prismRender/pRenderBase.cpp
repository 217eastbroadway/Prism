#include <pRender.h>

namespace pRender{
    void copyToRender(SDL_Renderer *renderer, SDL_Texture* srcTexture, SDL_Rect *destRectangle){
        SDL_RenderCopy(renderer, srcTexture, NULL, destRectangle);
    }
}