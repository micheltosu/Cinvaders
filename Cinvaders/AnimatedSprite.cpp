//
//  AnimatedSprite.cpp
//  CINVADERS
//
//  Created by Michel Tosu on 2019-01-08.
//  Copyright © 2019 Michel Tosu. All rights reserved.
//

#include "AnimatedSprite.h"
#include "GameObject.h"

#define MILLISECONDS 1000

namespace ToMingine {
    
AnimatedSprite::AnimatedSprite(std::string path, int num, int seconds = 1) : Sprite(path), frames(num), framesPerImage((seconds * MILLISECONDS) / num) {
    
    rect.w = rect.w / num;
    frameRect.h = rect.h;
    frameRect.w = rect.w;
    
}
    
void AnimatedSprite::draw() {

    rect.x = go->getRect()->x;
    rect.y = go->getRect()->y;
    
    updateFrame();
    
    frameRect.x = rect.w * (currentFrame - 1);
    frameRect.y = 0;
    
    SDL_RenderCopy(renderer, texture, &frameRect, &rect);
}
    
void AnimatedSprite::updateFrame() {
    
    int ticksSinceUpdate = SDL_GetTicks() - lastUpdate;
    
    if (ticksSinceUpdate >= framesPerImage){
        if (currentFrame >= frames)
            currentFrame = 1;
        else
            ++currentFrame;
        
        lastUpdate = SDL_GetTicks();
    }
}
    
    
    
}
