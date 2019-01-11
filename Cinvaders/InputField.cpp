#include "Inputfield.h"
#include "GameEngine.h"
#include <iostream>
#include <string>
namespace ToMingine {
    
    Inputfield::Inputfield(std::string path, int size) : Inputfield(path, size, 200, 200, 200,50) {}
    Inputfield::Inputfield(std::string path, int size, int x, int y, int w, int h) {
        rect.x = x;
        rect.y = y;
        rect.w = w;
        rect.h = h;
        
        box = new TextBox(path, size, rect);
        renOb = box;
        GameEngine::getInstance().mouseManager()->addListener(this);
        GameEngine::getInstance().keyboardManager()->addListener(this);
    }
    
    void Inputfield::mouseButtonEvent(const SDL_MouseButtonEvent& mev) {
        if(mev.type == SDL_MOUSEBUTTONUP &&
           mev.clicks == 1 &&
           (mev.x >= rect.x && mev.x <= (rect.x + rect.w)) &&
           (mev.y >= rect.y && mev.y <= (rect.y + rect.h))) {
            toggleFocus();
        } else if (focus &&
                   (mev.x > rect.x || mev.x < rect.x || mev.y > rect.y || mev.y < rect.y))
            toggleFocus();
    }
    
    void Inputfield::textInputEvent(const SDL_TextInputEvent& tev) {
        if(!focus) return;
        std::string inputChar(tev.text);
        box->addText(inputChar);
        
    }
    
    void Inputfield::keyBoardEvent(const SDL_KeyboardEvent& kev) {
        if (!focus) return;

        if (kev.type == SDL_KEYDOWN) {
            char pressedKey = kev.keysym.sym;
                switch (kev.keysym.sym) {
                    case SDLK_ESCAPE:
                        toggleFocus();
                        break;
                    case SDLK_BACKSPACE:
                        box->backSpace();
                        break;
                    case SDLK_RETURN:
                        //Fire some event
                        break;
                }
            }
        }
    
    void Inputfield::toggleFocus() {
        focus = !focus;
        
        if (focus)
            SDL_StartTextInput();
        else
            SDL_StopTextInput();
    }
    
    void Inputfield::tick() {
        if (dynamicSize) {
            rect.h = box->getTextHeight();
            rect.w = box->getTextWidth();
            box->setWidth(rect.w);
            box->setHeight(rect.h);
        }
        
        GameObject::tick();
    }
    
    Inputfield::~Inputfield() {
        delete renOb;
        GameEngine::getInstance().mouseManager()->removeListener(this);

        
        renOb = nullptr;
        box = nullptr; // samma objekt som renOb;
        
    }
    
    
}
