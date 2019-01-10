#include "PhysicsObject.h"


namespace ToMingine {

	PhysicsObject::PhysicsObject(std::string path, Type t):RigidObject(path, t){}

	PhysicsObject::PhysicsObject(Sprite * spr, Type t): RigidObject(spr, t){}

	PhysicsObject::PhysicsObject(std::string path, Type t, int x, int y): RigidObject(path, t, x, y){}

	PhysicsObject::PhysicsObject(Sprite * spr, Type t, int x, int y): RigidObject(spr, t, x, y) {}

	PhysicsObject::~PhysicsObject()	{}
	bool PhysicsObject::requestMove(int* x, int* y){
		*y += gravity;
		RigidObject::requestMove(*x, *y);
		return false;
	}
}