//
//  TextLabel.cpp
//  CINVADERS
//
#include "TextLabel.h"
#include "TextBox.h"

namespace ToMingine {
    TextLabel::TextLabel(std::string pth, int size) : TextLabel(pth, size, 500, 500, 100, 25, 10) {}
    TextLabel::TextLabel(std::string pth, int size, int x, int y, int w, int h, int pad = 10) {
        rect = {x, y, w, h};
        
        box = new TextBox(pth, size, rect, pad);
        renObj = box;
    }
    
    void TextLabel::setText(std::string str) {
        box->setText(str);
    }
    
    TextLabel::~TextLabel() {
        
        delete box;
        box = nullptr;
        renObj = nullptr;
        
    }
    
}
