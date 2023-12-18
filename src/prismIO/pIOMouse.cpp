#include <pIO.h>

namespace pIO{
    namespace mouseHandler{
        void movebymice(std::vector<pObject*> &vPrism){
            int x, y;
            SDL_GetMouseState(&x, &y);

            for(int i = vPrism.size()-1; i>=0; i--)
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