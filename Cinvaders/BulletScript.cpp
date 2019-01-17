#include "BulletScript.h"


BulletScript::BulletScript(int dir, RigidObject* ro):dir(dir), ro(ro){}

BulletScript::~BulletScript(){}

void BulletScript::run(){
	if (dir == 1)
		ro->move(0, -10);
	else if (dir == 2)
		ro->requestMove(10, 0);
	else if (dir == 3)
		ro->requestMove(0, 10);
	else if (dir == 4)
		ro->requestMove(-10, 0);

	if (ro->getRect()->x > GameEngine::getInstance().window_width || ro->getRect()->x < 0) {
		GameEngine::getInstance().getCurrentScene()->removeObject(ro);
	}
	if (ro->getRect()->y > GameEngine::getInstance().window_height || ro->getRect()->y < 0) {
		GameEngine::getInstance().getCurrentScene()->removeObject(ro);
	}
}

void BulletScript::collision(Type t){
	if (t == ENEMY)
		GameEngine::getInstance().getCurrentScene()->removeObject(ro);
}
