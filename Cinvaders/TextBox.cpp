#include "TextBox.h"
#include <iostream>

namespace ToMingine {
    TextBox::TextBox(std::string path, int size, SDL_Rect& parentRect, int boxPadding) {
        int minX, minY, maxY, advance;
        font = TTF_OpenFont(path.c_str(), size);
        TTF_GlyphMetrics(font, 'M', &minX, &em, &minY, &maxY, &advance);
        textSpacing = advance - em;
        
        padding = boxPadding;
        rect = { parentRect.x, parentRect.y, parentRect.h + padding, parentRect.w + padding };
        textRect = { parentRect.x + (padding), parentRect.x + (padding/2), parentRect.h, parentRect.w};
        
        colorFg = {0,0,0,255};
        colorBg = {255,255,255,255};
        
        
    }
    
    void TextBox::setColorFg(SDL_Color &other) {
        colorFg = {other.r, other.g, other.b, other.a};
    }
    
    void TextBox::setColorBg(SDL_Color &other) {
        colorBg = {other.r, other.g, other.b, other.r};
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
    
    void TextBox::updateCursor() {
        cursorRect.w = 2;
        cursorRect.h = textRect.h;
        cursorRect.y = textRect.y;
        cursorRect.x = textRect.x + textRect.w + textSpacing;
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
        
        if (showCursor) {
            if (SDL_GetTicks() - lastBlink > cursBlinkSpd) {
                updateCursor();
                visible = !visible;
                lastBlink = SDL_GetTicks();
            }
            
            if (visible)
                SDL_RenderFillRect(renderer, &cursorRect);

        }
    }
    
    void TextBox::resize() {
        
        
    }
    
    TextBox::~TextBox() {
        delete font;
        
    }
}
