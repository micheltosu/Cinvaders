#ifndef RENDERED_OBJECT_H
#define RENDERED_OBJECT_H


#ifdef _WIN32

#include <SDL.h>


#elif defined (__APPLE__)
#include <SDL2/SDL.h>


#endif
namespace ToMingine {


class RenderedObject {
public:
    RenderedObject();
    virtual ~RenderedObject();
    virtual void draw() = 0;
    
    const SDL_Rect* getRect() { return &rect; }

	SDL_Surface* getSurface() { return surface; }

	//virtual unsigned long int getPixel(int, int) = 0;
    

protected:
    SDL_Renderer* renderer;
    SDL_Texture* texture = nullptr;
    SDL_Rect rect;
	SDL_Surface* surface;
    
};
}
#endif
