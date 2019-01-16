#include "TextBox.h"
#include <iostream>

namespace ToMingine {
    TextBox::TextBox(std::string path, int size, SDL_Rect& parentRect, int boxPadding) {
        int minX, minY, maxY, advance;
        font = TTF_OpenFont(path.c_str(), size);
        TTF_GlyphMetrics(font, 'M', &minX, &em, &minY, &maxY, &advance);
        textSpacing = advance - em;
        padding = boxPadding;
        
        txtSurf = TTF_RenderText_Solid(font, text.c_str(), colorFg);
        
        rect = { parentRect.x, parentRect.y, parentRect.w + padding, parentRect.h + padding,};
        textRect = { parentRect.x + (padding/ 2), parentRect.y + (padding/2), 0, parentRect.h};
        
        colorFg = {0,0,0,255};
        colorBg = {255,255,255,255};
    }
    
    void TextBox::setColorFg(SDL_Color &other) {
        colorFg = {other.r, other.g, other.b, other.a};
        updateTextSurface();
    }
    
    void TextBox::setColorBg(SDL_Color &other) {
        colorBg = {other.r, other.g, other.b, other.a};
        updateTextSurface();
    }
    
    void TextBox::setText(std::string txt) {
        text = txt;
        updateTextSurface();
    }

    void TextBox::resize() {
        rect = {rect.x, rect.y, textRect.w + padding, textRect.h + padding};
    }
    
    void TextBox::updateTextSurface() {
        SDL_FreeSurface(txtSurf);
        txtSurf = TTF_RenderText_Solid(font, text.c_str(), colorFg);
        
        if(txtSurf->w != textRect.w)
            textRect.w = txtSurf->w;
        if(txtSurf->h != textRect.h)
            textRect.h = txtSurf->h;
    }
    
    void TextBox::draw() {
        SDL_Texture* textTxt = SDL_CreateTextureFromSurface(renderer, txtSurf);
        
        SDL_SetRenderDrawColor(renderer, colorBg.r, colorBg.g, colorBg.b, colorBg.a);
        SDL_RenderFillRect(renderer, &rect);
        
        SDL_SetRenderDrawColor(renderer, colorFg.r, colorFg.g, colorFg.b, colorFg.a);
        SDL_RenderDrawRect(renderer, &rect);
        
        SDL_RenderCopy(renderer, textTxt, NULL, &textRect);
        SDL_DestroyTexture(textTxt);
    }
    
    TextBox::~TextBox() {
        delete font;
        SDL_FreeSurface(txtSurf);
    }
}
