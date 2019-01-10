#include "Inputfield.h"

namespace ToMingine {
    
    Inputfield::Inputfield(std::string path, int size) : Inputfield(path, size, 200, 200, 200,50) {}
    Inputfield::Inputfield(std::string path, int size, int x, int y, int w, int h) {
        rect.x = x;
        rect.y = y;
        rect.w = w;
        rect.h = h;
        
        box = new TextBox(path, size, rect);
        renOb = box;
        
        
    }
    
    Inputfield::~Inputfield() {
        delete renOb;
        
        
        renOb = nullptr;
        box = nullptr; // samma objekt som renOb;
        
    }
    
    
}
