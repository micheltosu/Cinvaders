#include "EnemyScript.h"


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

void EnemyScript::collision(Type t){
	if (t == PLAYER)
		GameEngine::getInstance().getCurrentScene()->removeObject(ro);
}
