#include "PhysicsObject.h"


namespace ToMingine {

	PhysicsObject::PhysicsObject(std::string path, Type t):RigidObject(path, t){}

	PhysicsObject::PhysicsObject(Sprite * spr, Type t): RigidObject(spr, t){}

	PhysicsObject::PhysicsObject(std::string path, Type t, int x, int y): RigidObject(path, t, x, y){}

	PhysicsObject::PhysicsObject(Sprite * spr, Type t, int x, int y): RigidObject(spr, t, x, y) {}

	PhysicsObject::~PhysicsObject()	{}
	GameObject* PhysicsObject::requestMove(int* x, int* y){
		//*y += gravity;
		GameObject* go = RigidObject::requestMove(*x, *y);
		if (go) {
			bounce(go, x, y);
		}
		return nullptr;
	}
	void PhysicsObject::bounce(GameObject* go, int* x, int* y){

		if ((go->getRect()->x < (getRect()->x + getRect()->w) && (go->getRect()->x + go->getRect()->w) > getRect()->x) &&
			(go->getRect()->y > (getRect()->y + getRect()->h) || (go->getRect()->y + go->getRect()->h) < getRect()->y)
			) {
			*y *= -1 * elasticity;
		}
		if ((go->getRect()->y < (getRect()->y + getRect()->h) && (go->getRect()->y + go->getRect()->h) > getRect()->y) &&
			(go->getRect()->x > (getRect()->x + getRect()->w) || (go->getRect()->x + go->getRect()->w) < getRect()->x)
			) {
			*x *= -1 * elasticity;
		}

			
			
	}
}