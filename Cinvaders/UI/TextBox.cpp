#include "TextBox.h"
#include <iostream>

namespace ToMingine {
    TextBox::TextBox(std::string path, int size, SDL_Rect& parentRect, int boxPadding) {
        int minX, minY, maxY, advance;
        font = TTF_OpenFont(path.c_str(), size);
        TTF_GlyphMetrics(font, 'M', &minX, &em, &minY, &maxY, &advance);
        textSpacing = advance - em;
        
        padding = boxPadding;
        rect = { parentRect.x, parentRect.y, parentRect.w + padding, parentRect.h + padding,};
        textRect = { parentRect.x + (padding), parentRect.y + (padding/2), parentRect.w, parentRect.h};
        
        colorFg = {0,0,0,255};
        colorBg = {255,255,255,255};
    }
    
    void TextBox::setColorFg(SDL_Color &other) {
        colorFg = {other.r, other.g, other.b, other.a};
    }
    
    void TextBox::setColorBg(SDL_Color &other) {
        colorBg = {other.r, other.g, other.b, other.r};
    }
    
    void TextBox::setText(std::string txt) {
        text = txt;
    }

    void TextBox::resize() {
    }
    
    void TextBox::draw() {
        std::string drawText = !text.empty() ? text : text.append(" "); // Don't want zero length
        SDL_Surface* txtSurf = TTF_RenderText_Solid(font, drawText.c_str(), colorFg);
        SDL_Texture* textTxt = SDL_CreateTextureFromSurface(renderer, txtSurf);
        
        textRect.h = txtSurf->h;
        textRect.w = txtSurf->w;
        rect.h = txtSurf->h + padding;
        rect.w = txtSurf->w  + (em * 1.5);


        SDL_SetRenderDrawColor(renderer, colorBg.r, colorBg.g, colorBg.b, colorBg.a);
        SDL_RenderFillRect(renderer, &rect);
        
        SDL_SetRenderDrawColor(renderer, colorFg.r, colorFg.g, colorFg.b, colorFg.a);
        SDL_RenderDrawRect(renderer, &rect);
        
        SDL_RenderCopy(renderer, textTxt, NULL, &textRect);
        SDL_FreeSurface(txtSurf);

    }
    
    TextBox::~TextBox() {
        delete font;
        
    }
}
