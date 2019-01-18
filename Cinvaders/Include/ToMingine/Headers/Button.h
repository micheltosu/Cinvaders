//
//  Button.hpp
//  CINVADERS
//

#ifndef BUTTON_H
#define BUTTON_H
#include "TextLabel.h"
#include <functional>

namespace ToMingine {
    class Button : public TextLabel {
    public:
        Button(std::string path, std::string txt, std::function<void()> funk, SDL_Rect& pos, int textSize = 16);
        
        void mouseButtonEvent(const SDL_MouseButtonEvent&) override;
    private:
        std::function<void()> callback;
    };
}

#endif /* Button_hpp */
