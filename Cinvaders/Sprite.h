#ifndef SPRITE_H
#define SPRITE_H

#include <stdio.h>
#include <string>

#ifdef _WIN32

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#elif defined (__APPLE__)
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <SDL2_ttf/SDL_ttf.h>
#endif

namespace ToMingine {

class GameObject;
    
class Sprite {
public:
    virtual void draw();
    void addGameObject(GameObject*);
    
    Sprite(std::string);
    virtual ~Sprite();
	const SDL_Rect* getRect() { return &rect; }
protected:
    SDL_Rect rect;
    
    Sprite(const Sprite&) = delete;
    const Sprite& operator=(const Sprite&) = delete;
    
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    GameObject* go;

};
    
}
#endif /* SPRITE_H */
