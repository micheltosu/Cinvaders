#include "Inputfield.h"
#include "GameEngine.h"
#include <iostream>
#include <string>
namespace ToMingine {
    
    Inputfield::Inputfield(std::string path, int size) : Inputfield(path, size, 200, 200, 200,50) {}
    Inputfield::Inputfield(std::string path, int size, int x, int y, int w, int h) :
        TextLabel(path, size, x, y, w, h) {
            
        rect.x = x;
        rect.y = y;
        rect.w = w;
        rect.h = h;
        
        box = new EditableTextBox(path, size, rect);
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
        } else if (focus && mev.type == SDL_MOUSEBUTTONUP && 
                   (mev.x > rect.x || mev.x < rect.x || mev.y > rect.y || mev.y < rect.y))
            toggleFocus();
    }
    
    void Inputfield::textInputEvent(const SDL_TextInputEvent& tev) {
        if(!focus) return;
        std::string inputChar(tev.text);
        dynamic_cast<EditableTextBox*>(box)->addText(inputChar);
        
    }
    
    void Inputfield::keyBoardEvent(const SDL_KeyboardEvent& kev) {
        if (!focus) return;

        if (kev.type == SDL_KEYDOWN) {
                switch (kev.keysym.sym) {
                    case SDLK_ESCAPE:
                        toggleFocus();
                        break;
                    case SDLK_BACKSPACE:
                        dynamic_cast<EditableTextBox*>(box)->backSpace();
                        break;
                    
                }
            }
        }
    
    void Inputfield::toggleFocus() {
        focus = !focus;
        dynamic_cast<EditableTextBox*>(box)->toggleCursor();
        
        if (focus)
            SDL_StartTextInput();
        else
            SDL_StopTextInput();
    }
    
    void Inputfield::tick() {
        if (dynamicSize) {
            box->resize();
            rect = box->getRect();
            
        }
        
        GameObject::tick();
    }
    
    Inputfield::~Inputfield() {
        GameEngine::getInstance().mouseManager()->removeListener(this);
       
    }
    
    
}
