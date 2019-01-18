#include "BulletScript.h"


BulletScript::BulletScript(int dir, RigidObject* ro):dir(dir), ro(ro){}

BulletScript::~BulletScript(){
    ro = nullptr;
}

void BulletScript::run(){
	if (dir == 1) {
		int x = 0, y = -10;
		ro->requestMove(x,y);
	}
	else if (dir == 2) {
		int x = 10, y = 0;
		ro->requestMove(x,y);
	}
	else if (dir == 3) {
		int x = 0, y = 10;
		ro->requestMove(x, y);
	}
	else if (dir == 4) {
		int x = -10, y = 0;
		ro->requestMove(x, y);
	}

	if (ro->getRect()->x > GameEngine::getInstance().window_width || ro->getRect()->x < 0) {
		GameEngine::getInstance().getCurrentScene()->removeObject(ro);
	}
	if (ro->getRect()->y > GameEngine::getInstance().window_height || ro->getRect()->y < 0) {
		GameEngine::getInstance().getCurrentScene()->removeObject(ro);
	}
}

void BulletScript::collision(Type t){
	std::cout << "bullet hit!" << std::endl;
	if (t == ENEMY)
		GameEngine::getInstance().destroyGameOject(ro);
}
