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
        GameEngine::getInstance().keyboardManager()->addListener(this)
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
    
    void Inputfield::keyBoardEvent(Uint32 key) {
        if (!focus) return;
        std::string keyName = SDL_GetKeyName(key);
        
        box->addText(keyName);
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
