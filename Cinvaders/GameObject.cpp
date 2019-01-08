#include "GameObject.h"
#include "GameEngine.h"


namespace ToMingine {
	
    GameObject::GameObject () {}
    GameObject::GameObject(Sprite* spr) : GameObject(spr, 0, 0) {}
    GameObject::GameObject(Sprite* spr, int x, int y) {
		
       
        sprite = spr;
        sprite->addGameObject(this);
        
        rect.x = x;
        rect.y = y;
		
	}

	GameObject::~GameObject() {	}

	void GameObject::tick() {
		if (script != nullptr) {
			script->run();
		}
		draw();
	}

	void GameObject::keyBoardEvent(Uint32 key) {
		if (script != nullptr)
			script->keyBoardEvent(key);
	}

	void GameObject::draw() {
        if (sprite != nullptr) sprite->draw();
    }


}
