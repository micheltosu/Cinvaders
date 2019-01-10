#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include <vector>
#include "Script.h"
#include "Sprite.h"

namespace ToMingine {

enum Type { PLAYER, ENEMY, AMMO, NIL };
class GameObject {
public:
    GameObject();
    GameObject(Sprite* spr, Type t);
    GameObject(Sprite* spr, Type t, int x, int y);
    ~GameObject();

    void addScript(Script* s) { script = s; }
    void tick();
    void keyBoardEvent(Uint32);

    SDL_Rect* getRect() { return &rect; }
	Type getType() { return type; }

protected:
    SDL_Rect rect;
	Type type;
    Script* script = nullptr;
    RenderedObject* renOb = nullptr;

private:
    void draw();
    
    int width, height; // The gameObject width and height
    int xPos, yPos; // The gameOject's position

    
    

};
}
#endif
