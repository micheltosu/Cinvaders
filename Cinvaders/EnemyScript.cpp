#include "EnemyScript.h"
#include "BulletScript.h"

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
    shoot(0);
}

void EnemyScript::shoot(Uint32){
   /* int x = ro->getRect()->x +(ro->getRect()->w / 2);
    int y = ro->getRect()->y -(ro->getRect()->h / 2);
    RigidObject* bullet = RigidObject::create(new Sprite("Resources/Image/plus bullet.png"), PLAYER, x - 7, y+ ro->getSurface()->h);
    bullet->addScript(new BulletScript(3, bullet));
    GameEngine::getInstance().getCurrentScene()->addObject(bullet);*/
}

void EnemyScript::collision(Type t){
	if (t == PLAYER)
		GameEngine::getInstance().destroyGameOject(ro);
}
