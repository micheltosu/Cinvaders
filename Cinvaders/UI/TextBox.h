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
    void resize();
    
    int getPadding() { return padding; }
    SDL_Rect getRect() {return SDL_Rect(rect); }
    SDL_Color getColorFg() { return colorFg; }
    SDL_Color getColorBg() { return colorBg; }
    std::string getText() { return text; }
    
    
protected:
    
    TextBox(const TextBox&) = delete;
    const TextBox& operator=(const TextBox&) = delete;
    TTF_Font* font;
    SDL_Color fontColor = {0,0,0};
    std::string text = "Textbox";
    
    int em;
    int padding;
    int textSpacing;
    SDL_Color colorFg, colorBg;
    SDL_Rect textRect;

};

}
#endif /* TextBox_hpp */
