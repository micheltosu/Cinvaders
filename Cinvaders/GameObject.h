#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include <vector>
#include "Script.h"
#include "Sprite.h"

namespace ToMingine {

class GameObject {

public:
    GameObject();
    GameObject(Sprite* spr);
    GameObject(Sprite* spr, int x, int y);
    ~GameObject();

    void addScript(Script* s) { script = s; }
    void tick();
    void keyBoardEvent(Uint32);

    SDL_Rect* getRect() { return &rect; }

protected:
    SDL_Rect rect;

private:
    void draw();
    
    int width, height; // The gameObject width and height
    int xPos, yPos; // The gameOject's position

    Script* script = nullptr;
    Sprite* sprite = nullptr;
    

};
}
#endif
