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
    
    void TextBox::addChar(char ch)  {
        text.push_back(ch);
    }
    
    void TextBox::backSpace() {
        text.pop_back();
    }
    
    void TextBox::draw() {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 150);
        SDL_RenderFillRect(renderer, &rect);
        
        std::string drawText = !text.empty() ? text : text.append(" "); // Don't want zero length
        
        SDL_Surface* txtSurf = TTF_RenderText_Solid(font, drawText.c_str(), fontColor);
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
