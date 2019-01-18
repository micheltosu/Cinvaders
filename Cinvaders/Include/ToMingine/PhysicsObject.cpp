#include "PhysicsObject.h"


namespace ToMingine {
	PhysicsObject::PhysicsObject(Sprite * spr, Type t): RigidObject(spr, t){}
	PhysicsObject::PhysicsObject(Sprite * spr, Type t, int x, int y): RigidObject(spr, t, x, y) {}
    
    PhysicsObject* PhysicsObject::create(Sprite *spr, Type t, int x, int y) {
        return new PhysicsObject(spr, t, x, y);
    }

	PhysicsObject::~PhysicsObject()	{
        collisionObject = nullptr;
    }
	GameObject* PhysicsObject::requestMove(int* x, int* y){
		Direction dir;
		*y += gravity;
		GameObject* go = RigidObject::requestMove(*x, *y, dir);
		if (go) {
			bounce(go, x, y, dir);
		}
		return nullptr;
	}
	void PhysicsObject::bounce(GameObject* go, int* x, int* y, Direction dir){
		if(dir == VERT)
			*x *= -1 * elasticity;
		if(dir == HORIZ)
			*y *= -1 * elasticity;
	}
}
