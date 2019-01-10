#include "GameObject.h"
#include "GameEngine.h"


namespace ToMingine {
    
    GameObject::GameObject () {}
    GameObject::GameObject(Sprite* spr, Type t) : GameObject(spr, t, 0, 0) {}
    GameObject::GameObject(Sprite* spr, Type t, int x, int y) {
        
        type = t;
        
        spr->addGameObject(this);
        renOb = spr;
        
        
        rect.x = x;
        rect.y = y;
        rect.w = renOb->getRect()->w;
        rect.h = renOb->getRect()->h;
        
    }

	GameObject::~GameObject() {
		delete script;
		delete renOb;
        
        script = nullptr;
        renOb = nullptr;
	}

    void GameObject::tick() {
        if (script) {
            script->run();
        }
        draw();

    }

    void GameObject::keyBoardEvent(Uint32 key) {
        if (script != nullptr)
            script->keyBoardEvent(key);
    }

    void GameObject::draw() {
        if (renOb != nullptr) renOb->draw();
    }


}
