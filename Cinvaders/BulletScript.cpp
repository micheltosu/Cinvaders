#include "BulletScript.h"


BulletScript::BulletScript(int dir, RigidObject* ro):dir(dir), ro(ro){}

BulletScript::~BulletScript(){
}

void BulletScript::run(){
	if (dir == 1)
		ro->move(0, -10);
	else if (dir == 2)
		ro->move(10, 0);
	else if (dir == 3)
		ro->move(0, 10);
	else if (dir == 4)
		ro->move(-10, 0);

	if (ro->getRect()->x > GameEngine::getInstance().window_width)
	if (ro->getRect()->y > GameEngine::getInstance().window_height)
}


