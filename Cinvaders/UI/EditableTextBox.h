//
//  EditableTextBox.h
//  CINVADERS
//

#ifndef EDITABLETEXTBOX_H
#define EDITABLETEXTBOX_H

#include "TextBox.h"
#include <string>

namespace ToMingine {
class EditableTextBox : public TextBox {
public:
    ~EditableTextBox();
    EditableTextBox(std::string, int size, SDL_Rect& parentRect, int boxPadding = 10);
    void addText(std::string);
    void addChar(char);
    void backSpace();
    void toggleCursor() { showCursor = !showCursor; }
    int getTextWidth() { return textRect.w; }
    int getTextHeight() { return textRect.h; }

    void draw() override;
    void resize() override;

    
protected:
    void updateTextSurface() override;
    void updateCursor();
    int cursBlinkSpd = 500, lastBlink = 0;
    bool showCursor = false, cursorVisible = false;
    SDL_Rect cursorRect;

};
}
#endif /* EDITABLETEXTBOX_H */

