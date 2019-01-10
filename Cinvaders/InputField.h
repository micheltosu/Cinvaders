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
    
    void tick();
private:
    bool focus, dynamicSize = true;
    TextBox *box;

    
    Inputfield(const Inputfield&) = delete;
    const Inputfield& operator=(const Inputfield&) = delete;
};
}

#endif /* INPUTFIELD_H */
