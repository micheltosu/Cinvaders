//
//  AnimatedSprite.hpp
//  CINVADERS
//
//  Created by Michel Tosu on 2019-01-08.
//  Copyright © 2019 Michel Tosu. All rights reserved.
//

#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include "Sprite.h"

namespace ToMingine {

class AnimatedSprite: public Sprite {
public:
    void draw();
    
    AnimatedSprite(std::string path, int num, int seconds);
    
protected:
    int frames, framesPerImage;
    int currentFrame = 1;
    int animSpeed;
    int lastUpdate;
    SDL_Rect frameRect;
    
private:
    void updateFrame();
};

}
#endif /* AnimatedSprite_hpp */
