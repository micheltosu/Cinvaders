//
//  TextLabel.cpp
//  CINVADERS
//
#include "TextLabel.h"
#include "TextBox.h"

namespace ToMingine {
    TextLabel::TextLabel(std::string pth, int size) : TextLabel(pth, size, 500, 500, 100, 25, 10) {}
    TextLabel::TextLabel(std::string pth, int size, int x, int y, int w, int h, int pad) {
        rect = {x, y, w, h};
        
        box = new TextBox(pth, size, rect, pad);
        renOb = box;
    }
    
    void TextLabel::setText(std::string str) {
        box->setText(str);
        box->resize();
        
        rect = box->getRect();
    }
    
    TextLabel::~TextLabel() {
        
        delete box;
        box = nullptr;
        renOb = nullptr;
        
    }
    
}
