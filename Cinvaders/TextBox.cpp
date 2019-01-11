#include "TextBox.h"
#include <iostream>

namespace ToMingine {
    TextBox::TextBox(std::string path, int size, SDL_Rect& parentRect) {
    
        rect.h = parentRect.h;
        rect.w = parentRect.w;
        rect.x = parentRect.x;
        rect.y = parentRect.y;
        
        font = TTF_OpenFont(path.c_str(), size);
    }
    
    void TextBox::addText(std::string txt) {
        text.append(txt);
    }
    
    void TextBox::draw() {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 150);
        SDL_RenderFillRect(renderer, &rect);
        
        SDL_Surface* txtSurf = TTF_RenderText_Solid(font, text.c_str(), fontColor);
        SDL_Texture* textTxt = SDL_CreateTextureFromSurface(renderer, txtSurf);
        
        textWidth = txtSurf->w;
        textHeight = txtSurf->h;
        
        SDL_RenderCopy(renderer, textTxt, NULL, &rect);
        SDL_FreeSurface(txtSurf);
    }
    
    TextBox::~TextBox() {
        delete font;
        
    }
}
