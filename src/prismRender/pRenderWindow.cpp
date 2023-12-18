#include <pRender.h>

namespace pRender{
    void clearWindow(SDL_Renderer *renderer){
        SDL_RenderClear(renderer);
    }

    void updateWindow(SDL_Renderer *renderer){
        SDL_RenderPresent(renderer);
    }
}