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

    void EditableTextBox::updateTextSurface() {
        std::string drawText = !text.empty() ? text : text.append(" "); // Don't want zero length
        TextBox::updateTextSurface();
//
//        SDL_FreeSurface(txtSurf);
//        txtSurf = TTF_RenderText_Solid(font, drawText.c_str(), colorFg);
    }

    
    void EditableTextBox::draw() {
        updateTextSurface();
        TextBox::draw();
        
        rect.h = textRect.h + padding;
        rect.w = textRect.w  + (em * 1.5);
        
        if (showCursor) {
            updateCursor();
            
            if (SDL_GetTicks() - lastBlink > cursBlinkSpd) {
                cursorVisible = !cursorVisible;
                lastBlink = SDL_GetTicks();
            }
            
            if (cursorVisible)
                SDL_RenderFillRect(renderer, &cursorRect);
            
        }
    }
    
    EditableTextBox::~EditableTextBox() {
        
    }

}
