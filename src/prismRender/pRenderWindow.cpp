#include <pRender.h>

namespace pRender{
    void clearScreen(){
        SDL_RenderClear(renderer);
    }

    void updateScreen(){
        SDL_RenderPresent(renderer);
    }
}