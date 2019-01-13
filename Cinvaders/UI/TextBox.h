#ifndef TEXTBOX_H
#define TEXTBOX_H

#ifdef _WIN32
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>


#elif defined (__APPLE__)
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#endif

#include "RenderedObject.h"
#include <string>

namespace ToMingine {
    
class TextBox : public RenderedObject {
public:
    TextBox(std::string, int size, SDL_Rect& parentRect, int boxPadding = 10);
    ~TextBox();
    
    void draw();
    void setHeight(int h) { rect.h = h; }
    void setWidth(int w) { rect.w = w; }
    void setColorFg(SDL_Color&);
    void setColorBg(SDL_Color&);
    void setText(std::string txt);
    void addText(std::string txt);
    void addChar(char);
    void backSpace();
    void resize();
    void toggleCursor() { showCursor = !showCursor; }
    
    int getTextWidth() { return textRect.w; }
    int getTextHeight() { return textRect.h; }
    int getPadding() { return padding; }
    SDL_Rect getRect() {return SDL_Rect(rect); }
    SDL_Color getColorFg() { return colorFg; }
    SDL_Color getColorBg() { return colorBg; }
    std::string getText() { return text; }
    
    
private:
    void updateCursor();

    TextBox(const TextBox&) = delete;
    const TextBox& operator=(const TextBox&) = delete;
    TTF_Font* font;
    SDL_Color fontColor = {0,0,0};
    std::string text = "Input text here";
    
    int em;
    int padding;
    int textSpacing;
    int cursBlinkSpd = 500, lastBlink = 0;
    bool showCursor = false, visible = false;
    SDL_Rect textRect;
    SDL_Rect cursorRect;
    SDL_Color colorFg, colorBg;
};

}
#endif /* TextBox_hpp */
