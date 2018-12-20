#include "RigidObject.h"
#include "GameEngine.h"

namespace ToMingine {

	RigidObject::RigidObject(std::string path):GameObject(path){
	}

	RigidObject::RigidObject(std::string path, int x, int y) : GameObject(path, x, y) {
	}


	RigidObject::~RigidObject(){
	}

	void RigidObject::move(int x, int y) {
		if (GameEngine::getInstance().requestMove(this)) {
			rect.x += x;
			rect.y += y;
		}
	}
}