//
//  TextLabel.hpp
//  CINVADERS
//

#ifndef TEXTLABEL_H
#define TEXTLABEL_H

#include "GameObject.h"
#include "TextBox.h"

namespace ToMingine {
class TextLabel : public GameObject {
public:
    ~TextLabel();
    TextLabel(std::string, int size);
    TextLabel(std::string, int size, int x, int y, int w, int h, int pad = 10);
    
    
    void setText(std::string);
    std::string getText();
    
protected:
    
    
private:
    std::string text;
    TextBox* box;
    TextLabel(const TextLabel&) = delete;
    const TextLabel& operator= (const TextLabel&) = delete;

};
}
#endif /* TEXTLABEL_H */
