#include <pWindow.h>

namespace pWindow{
    void createWindow(int width, int height, int posX, int posY, const char* winName){
        if (SDL_Init(SDL_INIT_VIDEO) != 0){
            puts("Error initializing video output.");
            exit(-1);
        }
        if(TTF_Init() == -1)
            std::cout << SDL_GetError() << std::endl;

        win = SDL_CreateWindow(winName, posX, posY, width, height, SDL_WINDOW_RESIZABLE);
        if (!win){
            puts("Error creating window.");
            SDL_Quit();
        }

        if(!renderer)
            renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (!renderer){
            puts("Error creating renderer.");
            SDL_DestroyWindow(win);
            SDL_Quit();
        }
    }
}