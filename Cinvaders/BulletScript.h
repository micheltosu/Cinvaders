#ifndef BULLET_SCRIPT_H
#define BULLET_SCRIPT_H

#include "ToMingine.h"

using namespace ToMingine;
class BulletScript : public Script {
public:
	BulletScript(int dir, RigidObject* ro);
	~BulletScript();
	void run();
	void collision(Type t);
    GameObject* getGameObject() { return ro; }
private:
	RigidObject* ro;
	int dir;
};

#endif // !BULLET_SCRIPT_H
