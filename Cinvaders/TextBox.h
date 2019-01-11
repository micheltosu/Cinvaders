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
    TextBox(std::string, int size, SDL_Rect& parentRect);
    ~TextBox();
    
    void draw();
    void setHeight(int h) { rect.h = h; }
    void setWidth(int w) { rect.w = w; }
    void addText(std::string txt);
    
    int getTextWidth() { return textWidth; }
    int getTextHeight() { return textHeight; }
    
private:
    TextBox(const TextBox&) = delete;
    const TextBox& operator=(const TextBox&) = delete;
    TTF_Font* font;
    SDL_Color fontColor = {0,0,0};
    std::string text = "--------------Player XXX-------------";
    
    int textWidth, textHeight;
};

}
#endif /* TextBox_hpp */
