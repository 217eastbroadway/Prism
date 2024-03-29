#include <pObject.h>

pTextObject::pTextObject(const char* id, const char* text, const char* fontDir, int fontSize, SDL_Color textColor, int posX, int posY, bool isMovable, bool isHoverable){
    this->id = id;
    this->text = text;
    this->fontSize = fontSize;
    this->textColor = textColor;
    this->fontDir = fontDir;
    
    TTF_Font* tempFont = TTF_OpenFont(fontDir, fontSize);
    texture = pText::textToTexture(text, tempFont, textColor);

    pText::getFontSize(text, tempFont, &rect.w, &rect.h);
    setPos(posX, posY);

    isAnchored = false;
    this->isMovable = isMovable;
    this->isHoverable = isHoverable;

    TTF_CloseFont(tempFont);
    //std::cout << "Text Object was created! -> " << this << " -> " << id << " -> " << text << std::endl;
}

pTextObject::pTextObject(const pTextObject &copy){
    this->id = id;
    this->text = copy.text;
    this->fontSize = copy.fontSize;
    this->fontDir = copy.fontDir;

    this->texture = copy.texture;
    //std::cout << "Copy constructor called! -> " << this << " -> " << id << std::endl;
}

pTextObject::~pTextObject(){
    //std::cout << "Destroyed text object. -> " << this << " -> " << id << " -> " << text << std::endl;
}