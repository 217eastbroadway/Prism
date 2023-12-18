#include <pIO.h>

namespace pIO{
    namespace mouseHandler{
        void anchorObjects(std::vector<pObject*> &vPrism){
            SDL_Rect checkRect;
            checkRect.w = 1;
            checkRect.h = 1;
            SDL_GetMouseState(&checkRect.x, &checkRect.y);
            
            for(int i = vPrism.size()-1; i>=0; i--){
                SDL_Rect vectorRect = vPrism[i]->getRect();
                if(SDL_HasIntersection(&checkRect, &vectorRect)){
                        vPrism[i]->setAnchor(checkRect.x - vectorRect.x, checkRect.y - vectorRect.y);
                        vPrism[i]->setIsAnchored(true);

                        return;
                }
            }
        }

        void deanchorObjects(std::vector<pObject*> &vPrism){
            for(int i = vPrism.size()-1; i>=0; i--)
                if(vPrism[i]->getIsAnchored()){
                    vPrism[i]->setAnchor(500, 500);
                    vPrism[i]->setIsAnchored(false);
                }
        }
    }
}