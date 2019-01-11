#ifndef INPUTFIELD_H
#define INPUTFIELD_H

#include "GameObject.h"
#include "TextBox.h"

namespace ToMingine {
class Inputfield : public GameObject {
public:
    Inputfield(std::string path, int size = 12);
    Inputfield(std::string path, int size, int x, int y, int w, int h);
    ~Inputfield();
    
    void mouseButtonEvent(const SDL_MouseButtonEvent& mev) override;
    void textInputEvent(const SDL_TextInputEvent& tev) override;
    void keyBoardEvent(const SDL_KeyboardEvent&) override;
    void tick() override;
private:
    bool focus = false, dynamicSize = true;
    TextBox *box;

    void toggleFocus();
    
    Inputfield(const Inputfield&) = delete;
    const Inputfield& operator=(const Inputfield&) = delete;
};
}

#endif /* INPUTFIELD_H */
