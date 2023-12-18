#include <pObject.h>

void pObject::update(){
    pRender::copyToRender(rend, texture, &rect);
}