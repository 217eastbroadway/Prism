#include <pObject.h>   

SDL_Rect pObject::getRect(){
    return rect;
}

const char* pObject::getID(){
    return id.c_str();
}

void pObject::getAnchor(int& anchorX, int& anchorY){
    anchorX = this->anchorX;
    anchorY = this->anchorY;
}

bool pObject::getIsAnchored(){
    return isAnchored;
}

bool pObject::getIsHovered(){
    return isHovered;
}

bool pObject::getIsMovable(){
    return isMovable;
}

bool pObject::getIsHoverable(){
    return isHoverable;
}