#include <pRender.h>

namespace pRender{
    void clearWindow(){
        SDL_RenderClear(renderer);
    }

    void updateWindow(){
        SDL_RenderPresent(renderer);
    }
}