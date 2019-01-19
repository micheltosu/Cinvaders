#ifndef SPRITE_H
#define SPRITE_H

#include <stdio.h>
#include <string>
#include "RenderedObject.h"

#ifdef _WIN32

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#elif defined (__APPLE__)
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#endif

namespace ToMingine {

class GameObject;
    
class Sprite : public RenderedObject {
public:
    
    void draw();
    void addGameObject(GameObject*);
    
    Sprite(std::string);
    ~Sprite();
	const SDL_Rect* getRect() { return &rect; }

	virtual unsigned long int getPixel(int, int);

protected:    
    Sprite(const Sprite&) = delete;
    const Sprite& operator=(const Sprite&) = delete;
    
    
    GameObject* go;

};
    
}
#endif /* SPRITE_H */
