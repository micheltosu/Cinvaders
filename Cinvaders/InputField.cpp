#include "Inputfield.h"
#include "GameEngine.h"
#include <iostream>
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
            focus = !focus;
            std::cout << "inputfield: Focus changed" << std::endl;
        }
    }
    
    void Inputfield::keyBoardEvent(const SDL_KeyboardEvent& kev) {
        if (!focus) return;

        if (kev.type == SDL_KEYDOWN) {
            char pressedKey = kev.keysym.sym;
            std::cout << "Charcode: " << kev.keysym.sym << ", repeat: " << kev.repeat + 1 << std::endl;
            if ((kev.repeat == 0) && (kev.repeat % 10 == 0)) {
                switch (kev.keysym.sym) {
                    case SDLK_ESCAPE:
                        focus = !focus;
                        break;
                    case SDLK_BACKSPACE:
                        box->backSpace();
                        break;
                    case SDLK_RETURN:
                        //Fire some event
                        break;
                }
                // Alphabetic chars are handled below
                if (pressedKey > 96 && pressedKey < 123) {
                    if (kev.keysym.mod & (KMOD_SHIFT)) {
                        pressedKey -= 32; // Translate to upper case.
                        std::cout << "Charcode and mod: " << (kev.keysym.sym | kev.keysym.mod) << std::endl;
                        
                    }
                    std::cout << pressedKey << std::endl;
                    box->addChar(pressedKey);
                } else if (pressedKey <= 96 && pressedKey >= 32){
                    box->addChar(pressedKey);

                }
            }
        }
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
