#include "GameObject.h"
#include "GameEngine.h"
#include "Script.h"


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
    
    GameObject* GameObject::create(Sprite* spr, Type t) {
        return new GameObject(spr, t);
    }
    
    GameObject* GameObject::create(Sprite *spr, Type t, int x, int y) {
        return new GameObject(spr, t, x, y);
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

    void GameObject::keyBoardEvent(const SDL_KeyboardEvent& kev) {
        if (script != nullptr)
            script->keyBoardEvent(kev);
    }
    
    void GameObject::textInputEvent(const SDL_TextInputEvent& tev) {
        if (script != nullptr)
            script->textInputEvent(tev);
    }


	bool GameObject::hasScript(){
		if (script)
			return true;
		return false;
	}

    void GameObject::draw() {
        if (renOb != nullptr) renOb->draw();
    }


}
