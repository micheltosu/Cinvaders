#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include <vector>
#include "Sprite.h"

namespace ToMingine {

enum Type { PLAYER, ENEMY, AMMO, WALL };
class Script;
class GameObject {
public:
    GameObject();
    GameObject(Sprite* spr, Type t);
    GameObject(Sprite* spr, Type t, int x, int y);
    virtual ~GameObject();
	
	GameObject(const GameObject& other) = delete;
	const GameObject& operator=(const GameObject& other) = delete;
	
    void addScript(Script* s) { script = s; }
    virtual void tick();
    virtual void keyBoardEvent(Uint32);
    virtual void mouseButtonEvent(const SDL_MouseButtonEvent&) {};

    SDL_Rect* getRect() { return &rect; }
    Type getType() { return type; }
    virtual void collision(Type) {}
    bool hasScript();
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
