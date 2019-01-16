#ifndef ENEMY_SCRIPT_H
#define ENEMY_SCRIPT_H

#include "ToMingine.h"

using namespace ToMingine;
class EnemyScript : public Script {
public:
	EnemyScript(RigidObject* ro);
	~EnemyScript();
private:
	RigidObject* ro;
	void run();
	const int DELAY = 1;
	const int tickInterval = 1000 / DELAY;
	int x, y;
	Uint32 nextTick = SDL_GetTicks() + tickInterval;
	void collision(Type t);
};

#endif // !ENEMY_SCRIPT_H
