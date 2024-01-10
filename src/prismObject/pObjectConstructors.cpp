#include <pObject.h>

pObject::pObject(const char* id, const char* textureDir, int w, int h, int posX, int posY, bool isMovable, bool isHoverable){
    this->id = id;
    texture = pRender::makeTextureFromImage(textureDir);

    rect.w = w;
    rect.h = h;
    rect.x = posX;
    rect.y = posY;

    this->isMovable = isMovable;
    this->isHoverable = isHoverable;

    isAnchored = false;
    isHovered = false;
    //std::cout << "Created successfully! -> " << this << " -> " << id << std::endl;
}

pObject::pObject(){
    //std::cout << "Created successfully! -> " << this << " -> " << id << std::endl;
}

pObject::pObject(const pObject& copy){
    this->texture = copy.texture;
    this->rect = copy.rect;
    this->id = copy.id;

    this->isMovable = isMovable;
    this->isHoverable = isHoverable;

    //printf("Copy constructor called! -> 0x%p\n", this);
}

pObject::~pObject(){
    SDL_DestroyTexture(texture);
    //std::cout << "Destroyed. -> " << this << " -> " << id << std::endl;
}