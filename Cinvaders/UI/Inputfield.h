#ifndef INPUTFIELD_H
#define INPUTFIELD_H

#include "TextLabel.h"
#include "EditableTextBox.h"

namespace ToMingine {
class Inputfield : public TextLabel {
public:
    ~Inputfield();
    Inputfield(std::string path, int size = 12);
    Inputfield(std::string path, int size, int x, int y, int w, int h);
    
    void mouseButtonEvent(const SDL_MouseButtonEvent& mev) override;
    void textInputEvent(const SDL_TextInputEvent& tev) override;
    void keyBoardEvent(const SDL_KeyboardEvent&) override;
    void tick() override;
private:
    bool focus = false, dynamicSize = true;
    void toggleFocus();
    
};
}

#endif /* INPUTFIELD_H */
