#include "Inputfield.h"

namespace ToMingine {
    
    Inputfield::Inputfield(std::string path, int size) : Inputfield(path, size, 100, 100, 200,50) {}
    Inputfield::Inputfield(std::string path, int size, int x, int y, int w, int h) {
        rect.x = x;
        rect.y = y;
        rect.w = w;
        rect.y = y;
        
        font = TTF_OpenFont(path.c_str(), size);
        
        
        
        
    }
    
    Inputfield::~Inputfield() {
        delete font;
        delete renOb;
        
        renOb = nullptr;
        font = nullptr;
    }
    
    void Inputfield::draw() {
        if (renOb)
            renOb->draw();
            
            
    }
}
