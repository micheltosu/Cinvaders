#include "RigidObject.h"
#include "GameEngine.h"

namespace ToMingine {

	RigidObject::RigidObject(std::string path, Type t):GameObject(new Sprite(path), t) { }

	RigidObject::RigidObject(std::string path, Type t, int x, int y) : GameObject(new Sprite(path), t, x, y) { }

	RigidObject::~RigidObject() { }

	bool RigidObject::requestMove(int x, int y){
		SDL_Rect* otherRect;
		std::list<GameObject*>* gameObjects = GameEngine::getInstance().getCurrentScene()->getGameObjects();
		for (GameObject* go : *gameObjects) {
			otherRect = go->getRect();
			if (go != this && type != go->getType()) {
				if (
					otherRect->y + otherRect->h >= getRect()->y + y &&
					getRect()->y + otherRect->h + y >= otherRect->y &&
					otherRect->x + otherRect->w >= getRect()->x + x &&
					getRect()->x + getRect()->w + x >= otherRect->x 
					) {
					GameEngine::getInstance().getCurrentScene()->removeObject(go);
					return false;
				}
			}
		}
		return true;
	}

	void RigidObject::move(int x, int y) {		
		if (requestMove(x, y)) {
			rect.x += x * SPEED;
			rect.y += y * SPEED;
		}
	}
}
