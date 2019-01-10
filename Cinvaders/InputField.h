#ifndef INPUTFIELD_H
#define INPUTFIELD_H

#ifdef _WIN32

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>


#elif defined (__APPLE__)
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#endif

#include "GameObject.h"
#include "TextBox.h"

namespace ToMingine {
class Inputfield : public GameObject {
public:
    Inputfield(std::string path, int size = 12);
    Inputfield(std::string path, int size, int x, int y, int w, int h);
    ~Inputfield();
	private:
    bool focus;
    TextBox *box;

    
    Inputfield(const Inputfield&) = delete;
    const Inputfield& operator=(const Inputfield&) = delete;
};
}

#endif /* INPUTFIELD_H */
