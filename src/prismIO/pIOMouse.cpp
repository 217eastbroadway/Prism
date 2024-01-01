#include <pIO.h>

namespace pIO{
    namespace mouseHandler{
        void movebymice(std::vector<pObject*> &vPrism){
            int x, y;
            SDL_GetMouseState(&x, &y);
            SDL_Rect checkRect;
            checkRect.w = checkRect.h = 1;
            checkRect.x = x;
            checkRect.y = y;


            for(int i = vPrism.size()-1; i>=0; i--){
                SDL_Rect vectorRect = vPrism[i]->getRect();
                if(SDL_HasIntersection(&checkRect, &vectorRect))
                    vPrism[i]->setIsHovered(true);
                else vPrism[i]->setIsHovered(false);

                if(vPrism[i]->getIsAnchored() && vPrism[i]->getIsMovable()){
                    int anchorX, anchorY;
                    vPrism[i]->getAnchor(anchorX, anchorY);
                    vPrism[i]->setPos(x - anchorX, y - anchorY);
                    
                    pRender::moveQueue(vPrism, i, vPrism.size()-1);
                    return;
                }
            }
        }
    }
}