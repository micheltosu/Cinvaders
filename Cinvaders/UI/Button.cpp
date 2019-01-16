//
//  Button.cpp
//  CINVADERS
//

#include "Button.h"
#include "GameEngine.h"

namespace ToMingine {
    Button::Button(std::string path, std::string txt, void (*funcPoint)(), SDL_Rect& pos, int textSize) : TextLabel(path, textSize, pos.x, pos.y, pos.w, pos.h), callback(funcPoint) {
        GameEngine::getInstance().mouseManager()->addListener(this);
        setText(txt);
    }
    
    void Button::mouseButtonEvent(const SDL_MouseButtonEvent &mev) {
        if (mev.type == SDL_MOUSEBUTTONUP &&
            (mev.x >= rect.x || mev.x <= (rect.x + rect.w)) &&
            (mev.y >= rect.y || mev.y <= (rect.y + rect.h))) {
            callback();
        }
    }
}
