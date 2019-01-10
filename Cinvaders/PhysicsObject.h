#ifndef PHYSICS_OBJECT_H
#define PHYSICS_OBJECT_H

#include "RigidObject.h"

namespace ToMingine {
class PhysicsObject : public RigidObject {
public:
	PhysicsObject(std::string path, Type t);
	~PhysicsObject();
};

}
#endif // !PHYSICS_OBJECT_H