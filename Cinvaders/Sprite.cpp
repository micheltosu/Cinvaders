#include "Sprite.h"
#include "GameEngine.h"
#include <iostream>
#include <exception>

namespace ToMingine {

    Sprite::Sprite(std::string path) {
        SDL_Surface *surface = IMG_Load(path.c_str());
        if (!surface) {
            throw std::runtime_error("Could not load file: " + path);
        }
        renderer = GameEngine::getInstance().getRen();
        texture = SDL_CreateTextureFromSurface(renderer, surface);

        rect.h = surface->h;
        rect.w = surface->w;
        
        SDL_FreeSurface(surface);
        
    }
    
     void Sprite::draw() {
         rect.x = go->getRect()->x;
         rect.y = go->getRect()->y;
         
         SDL_RenderCopy(renderer, texture, NULL, &rect);
    }
    
    void Sprite::addGameObject(GameObject* gmo) {
        go = gmo;
    }
    
    Sprite::~Sprite(){
		SDL_DestroyTexture(texture);
        
    }
    
}
