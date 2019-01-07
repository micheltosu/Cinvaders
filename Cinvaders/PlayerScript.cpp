#include "PlayerScript.h"
#include "GameEngine.h"
#include <iostream>

PlayerScript::PlayerScript(RigidObject* ro){
	this->ro = ro;
	SDL_Keycode sk = SDLK_w;
	//GameEngine::getInstance().keyboardManager()->addBinding(sk, moveUp);
}


PlayerScript::~PlayerScript() { }


void PlayerScript::run() {
		
	if (ro->getRect()->x > GameEngine::getInstance().window_width)
		ro->getRect()->x = 0 - ro->getRect()->w;
	if (ro->getRect()->x < 0 - ro->getRect()->w)
		ro->getRect()->x = GameEngine::getInstance().window_width;
	if (ro->getRect()->y > GameEngine::getInstance().window_height)
		ro->getRect()->y = 0 - ro->getRect()->h;
	if (ro->getRect()->y < 0 - ro->getRect()->h)
		ro->getRect()->y = GameEngine::getInstance().window_height;
	prePos = *ro->getRect();
	ro->move(x, y); 
	if (prePos.x == ro->getRect()->x && prePos.y == ro->getRect()->y) { x = 0; y = 0; }

}

void PlayerScript::keyBoardEvent(Uint32 key) {
	if (key == SDLK_s)
		y += 1;
	if (key == SDLK_w)
		y -= 1;
	if (key == SDLK_d)
		x += 1;
	if (key == SDLK_a)
		x -= 1;
}

void PlayerScript::moveUp() {
	std::cout << "HEJ!" << std::endl;
}
