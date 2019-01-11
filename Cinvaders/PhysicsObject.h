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

	GameObject* requestMove(int*, int*);
	void setGravity(int g) { gravity = g; }
	void setElasticity(double e) { elasticity = e; }
private:
	void bounce(GameObject*, int* x, int* y);
	double elasticity = 0.5;
	GameObject* collisionObject;
	int gravity = 1;
};

}
#endif // !PHYSICS_OBJECT_H