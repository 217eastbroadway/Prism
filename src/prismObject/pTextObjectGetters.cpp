#include <pObject.h>

const char* pTextObject::getText(){
    return text.c_str();
}

const char* pTextObject::getFontDir(){
    return fontDir.c_str();
}

int pTextObject::getFontSize(){
    return fontSize;
}

SDL_Color pTextObject::getTextColor(){
    return textColor;
}