#include <pWindow.h>

namespace pWindow{
    void getWindowPos(int &posX, int &posY){
        SDL_GetWindowPosition(win, &posX, &posY);
    }

    void getWindowSize(int &width, int &height){
        SDL_GetWindowSize(win, &width, &height);
    }
}