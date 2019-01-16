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
    virtual void resize();
    
    const int getPadding() const { return padding; }
    const SDL_Rect getRect() const {return SDL_Rect(rect); }
    const SDL_Color getColorFg() const { return colorFg; }
    const SDL_Color getColorBg() const { return colorBg; }
    const std::string getText() const { return text; }
    
    
protected:
    virtual void updateTextSurface();
    TextBox(const TextBox&) = delete;
    const TextBox& operator=(const TextBox&) = delete;
    
    int em;
    int padding;
    int textSpacing;
    SDL_Color colorFg, colorBg;
    SDL_Rect textRect;
    SDL_Surface* txtSurf;
    TTF_Font* font;
    std::string text = "Textbox";
};

}
#endif /* TextBox_hpp */
