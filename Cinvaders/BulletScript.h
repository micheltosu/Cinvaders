#ifndef BULLET_SCRIPT_H
#define BULLET_SCRIPT_H

#include "Script.h"
#include "GameEngine.h"
#include <SDL.h>

using namespace ToMingine;
class BulletScript : public Script {
public:
	BulletScript(int dir, RigidObject* ro);
	~BulletScript();
	void run();
private:
	RigidObject* ro;
	int dir;
};

#endif // !BULLET_SCRIPT_H