#include "TextBox.h"
#include <iostream>

namespace ToMingine {
    TextBox::TextBox(std::string path, int size, SDL_Rect& parentRect, int boxPadding) {
    
        padding = boxPadding;
        rect = { parentRect.x, parentRect.y, parentRect.h + padding, parentRect.w + padding };
        textRect = { parentRect.x + (padding/2), parentRect.x + (padding/2), parentRect.h, parentRect.w};
        
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
        
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &rect);
        
        std::string drawText = !text.empty() ? text : text.append(" "); // Don't want zero length
        
        SDL_Surface* txtSurf = TTF_RenderText_Solid(font, drawText.c_str(), fontColor);
        SDL_Texture* textTxt = SDL_CreateTextureFromSurface(renderer, txtSurf);
        
        textRect.h = txtSurf->h;
        textRect.w = txtSurf->w;
        rect.h = txtSurf->h + padding;
        rect.w = txtSurf->w + padding;

        
        SDL_RenderCopy(renderer, textTxt, NULL, &textRect);
        SDL_FreeSurface(txtSurf);
    }
    
    void TextBox::resize() {
        
        
    }
    
    TextBox::~TextBox() {
        delete font;
        
    }
}
