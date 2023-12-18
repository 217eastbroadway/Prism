#include <pObject.h>

void pTextObject::setText(const char* text){
    this->text = text;
    TTF_Font* tempFont = TTF_OpenFont(fontDir.c_str(), fontSize);

    SDL_DestroyTexture(texture);
    
    texture = pText::textToTexture(this->text.c_str(), tempFont, textColor, rend);
    pText::getFontSize(this->text.c_str(), tempFont, &rect.w, &rect.h);
    TTF_CloseFont(tempFont);
}

void pTextObject::setFont(const char* fontDir){
    this->fontDir = fontDir;

    setText(text.c_str());
}

void pTextObject::setFontSize(int fontSize){
    this->fontSize = fontSize;
}

void pTextObject::setTextColor(SDL_Color textColor){
    this->textColor = textColor;
    setText(text.c_str());
}
