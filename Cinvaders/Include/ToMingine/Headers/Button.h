//
//  Button.hpp
//  CINVADERS
//

#ifndef BUTTON_H
#define BUTTON_H
#include "TextLabel.h"

namespace ToMingine {
    class Button : public TextLabel {
    public:
        Button(std::string path, std::string txt, void (*funcPoint)(), SDL_Rect& pos, int textSize = 16);
        
        void mouseButtonEvent(const SDL_MouseButtonEvent&) override;
    private:
        void (*callback)();
    };
}

#endif /* Button_hpp */
