#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <time.h>
#include <string.h>

#define SDL_MAIN_HANDLED
#include <Prism.h>

void initSDL(SDL_Window*& win, SDL_Renderer*& rend, const char* configFile){
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        puts("Error initializing video output.");
        exit(-1);
    }
    if(TTF_Init() == -1)
        std::cout << SDL_GetError() << std::endl;

    std::ifstream filein;
    filein.open(configFile, std::ios::in);
    int x, y;
    filein >> x;
    filein >> y;

    std::string z;
    filein >> z;

        
    if(z == "fullscreen")
        win = SDL_CreateWindow("Prism - Beta 0.8", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, x, y, SDL_WINDOW_FULLSCREEN);
    else win = SDL_CreateWindow("Prism - Beta 0.8", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, x, y, SDL_WINDOW_RESIZABLE);

    if (!win){
        puts("Error creating window.");
        SDL_Quit();
    }

    rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    if (!rend){
      puts("Error creating renderer.");
      SDL_DestroyWindow(win);
      SDL_Quit();
    }
}

int main(int argc, const char** argv){
    SDL_Window* win;
    SDL_Renderer* rend;

    int fsociety = 0;

    initSDL(win, rend, "res/config/config.txt");
    std::vector<pObject*> vPrism;
    /*std::vector<std::string> vStr;

    vStr.push_back("res/textures/1.png");
    vStr.push_back("res/textures/2.png");
    vStr.push_back("res/textures/3.png");
    vStr.push_back("res/textures/t.png");
    vStr.push_back("res/textures/t1.png");

    for(int i = 0; i < vStr.size(); i++)
        vPrism.push_back(new pObject(std::to_string(i).c_str(), vStr[i].c_str(), rend, 400, 400, 100+(50*i), 100+(50*i)));

    vPrism.push_back(new pTextObject("nyobj", "New York", "res/fonts/helvetica_neue_25.ttf", 50, PRISMTEXTWHITE, 0, 0, rend));
    vPrism.push_back(new pTextObject("f-15", "F-15EX", "res/fonts/helvetica_neue_65.ttf", 50, PRISMTEXTRED, 0, 50, rend));
    vPrism.push_back(new pTextObject("F-35B", "F-35B", "res/fonts/helvetica_neue_65.ttf", 50, PRISMTEXTGREEN, 0, 100, rend));
    vPrism.push_back(new pTextObject("fsociety", "0", "res/fonts/helvetica_neue_65.ttf", 100, PRISMTEXTBLUE, 0, 200, rend));
    */

   	pLoader::loadPack("res/levels/test.txt", vPrism, rend);

    bool userQuit = false;
    while(!userQuit){
        SDL_Event ev;
        while(SDL_PollEvent(&ev)){
            if(ev.type == SDL_KEYDOWN){
                switch(ev.key.keysym.sym){
                    case SDLK_ESCAPE:
                        userQuit = true;
                        break;

                    case SDLK_1:
                        pRender::moveQueue(vPrism, 0, 1);
                        break;

                    case SDLK_F2:
                        std::cout << "Reloading." << std::endl;

                        for(int i = 0; i < vPrism.size(); i++)
                            delete vPrism[i];
                            
                        vPrism.clear();

                        pLoader::loadPack("res/levels/test.txt", vPrism, rend);

                        std::cout << "Reloaded!" << std::endl;
                        break;
                }
            }

            if(ev.type == SDL_MOUSEBUTTONDOWN)
                pIO::mouseHandler::anchorObjects(vPrism);

            if(ev.type == SDL_MOUSEBUTTONUP)
                pIO::mouseHandler::deanchorObjects(vPrism);
            
            if(ev.type == SDL_QUIT)
              userQuit = true;
        }
        pIO::mouseHandler::movebymice(vPrism);

        for(int i = 0; i < vPrism.size(); i++)
            if(strcmp(vPrism[i]->getID(), "fsociety") == 0){
                reinterpret_cast<pTextObject*>(vPrism[i])->setText(std::to_string(fsociety).c_str());
                break;
            }
        
        pRender::clearWindow(rend);
        for(int i = 0; i<vPrism.size(); i++)
            vPrism[i]->update();
        
        pRender::updateWindow(rend);

        fsociety++;
    }

    for(int i = 0; i < vPrism.size(); i++)
        delete vPrism[i];

    return 0;
}