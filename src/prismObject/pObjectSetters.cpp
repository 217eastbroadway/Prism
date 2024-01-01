#include <pObject.h>

void pObject::setAnchor(int anchorX, int anchorY){
    this->anchorX = anchorX;
    this->anchorY = anchorY;
}

void pObject::setIsAnchored(bool isAnchored){
    this->isAnchored = isAnchored;
}

void pObject::setIsHovered(bool isHovered){
    this->isHovered = isHovered;
}

void pObject::setIsMovable(bool isMovable){
    this->isMovable = isMovable;
}

void pObject::setIsHoverable(bool isHoverable){
    this->isHoverable = isHoverable;
}

void pObject::setTexture(const char* textureDir){
    SDL_DestroyTexture(texture);
    texture = pRender::makeTextureFromImage(rend, textureDir);
}

void pObject::setPos(int newx, int newy){
    this->rect.x = newx;
    this->rect.y = newy;
}