#ifndef PHYSICS_OBJECT_H
#define PHYSICS_OBJECT_H

#include "RigidObject.h"

namespace ToMingine {
class PhysicsObject : public RigidObject {
public:
	PhysicsObject(std::string path, Type t);
	PhysicsObject(Sprite* spr, Type t);
	PhysicsObject(std::string path, Type t, int x, int y);
	PhysicsObject(Sprite* spr, Type t, int x, int y);
	~PhysicsObject();

	bool requestMove(int, int);
};

}
#endif // !PHYSICS_OBJECT_H