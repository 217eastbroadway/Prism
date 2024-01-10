#include <pObject.h>

void pObject::update(){
    pRender::copyToRender(texture, &rect);
}

void pObject::updateRenderer(std::vector<pObject*> &vPrism){
    pRender::clearWindow();
    for(auto obj : vPrism)
        obj->update();
    pRender::updateWindow();
}