//
//  EditableTextBox.cpp
//  CINVADERS
//

#include "EditableTextBox.h"

namespace ToMingine {
    EditableTextBox::EditableTextBox(std::string path, int size, SDL_Rect& parenRect, int boxPadding) : TextBox(path, size, parenRect, boxPadding) {
        text = "Click to write";
    }
    
    void EditableTextBox::addText(std::string txt) {
        text.append(txt);
    }
    
    void EditableTextBox::addChar(char ch)  {
        text.push_back(ch);
    }
    
    void EditableTextBox::backSpace() {
        text.pop_back();
    }
    
    void EditableTextBox::updateCursor() {
        cursorRect.w = 2;
        cursorRect.h = textRect.h;
        cursorRect.y = textRect.y;
        cursorRect.x = textRect.x + textRect.w + textSpacing;
    }
    
    void EditableTextBox::draw() {
        TextBox::draw();
        
        if (showCursor) {
            updateCursor();
            
            if (SDL_GetTicks() - lastBlink > cursBlinkSpd) {
                visible = !visible;
                lastBlink = SDL_GetTicks();
            }
            
            if (visible)
                SDL_RenderFillRect(renderer, &cursorRect);
            
        }
    }
    
    EditableTextBox::~EditableTextBox() {
        
    }

}
