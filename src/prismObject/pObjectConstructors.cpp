#include <pObject.h>

pObject::pObject(const char* id, const char* textureDir, int w, int h, int posX, int posY, bool isMovable, SDL_Renderer* rend){
    this->id = id;
    this->rend = rend;
    texture = pRender::makeTextureFromImage(rend, textureDir);

    rect.w = w;
    rect.h = h;
    rect.x = posX;
    rect.y = posY;

    this->isMovable = isMovable;

    isAnchored = false;
    //std::cout << "Created successfully! -> " << this << " -> " << id << std::endl;
}

pObject::pObject(){
    //std::cout << "Created successfully! -> " << this << " -> " << id << std::endl;
}

pObject::pObject(const pObject& copy){
    this->rend = copy.rend;
    this->texture = copy.texture;
    this->rect = copy.rect;
    this->id = copy.id;

    printf("Copy constructor called! -> 0x%p\n", this);
}

pObject::~pObject(){
    SDL_DestroyTexture(texture);
    std::cout << "Destroyed. -> " << this << " -> " << id << std::endl;
}