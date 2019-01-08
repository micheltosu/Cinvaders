#include "EnemyScript.h"
#include <stdlib.h>



EnemyScript::EnemyScript(RigidObject* ro): ro(ro){ }


EnemyScript::~EnemyScript(){}

void EnemyScript::run(){
	
	int delay = nextTick - SDL_GetTicks();
	if (delay < 0) {
		nextTick = SDL_GetTicks() + tickInterval;
		x = rand() % 3 - 1;
		y = rand() % 3 - 1;
	}
	ro->move(x, y);

		
}
