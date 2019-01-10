#include "GameObject.h"
#include "GameEngine.h"


namespace ToMingine {
    
    GameObject::GameObject () {}
    GameObject::GameObject(Sprite* spr, Type t) : GameObject(spr, t, 0, 0) {}
    GameObject::GameObject(Sprite* spr, Type t, int x, int y) {
        
        type = t;
        sprite = spr;
        sprite->addGameObject(this);
        
        rect.x = x;
        rect.y = y;
        rect.w = sprite->getRect()->w;
        rect.h = sprite->getRect()->h;
        
    }

	GameObject::~GameObject() {
		delete script;
		delete sprite;
	}

    void GameObject::tick() {
		draw();
        if (script) {
            script->run();
        }
    }

    void GameObject::keyBoardEvent(Uint32 key) {
        if (script != nullptr)
            script->keyBoardEvent(key);
    }

    void GameObject::draw() {
        if (sprite != nullptr) sprite->draw();
    }


}
