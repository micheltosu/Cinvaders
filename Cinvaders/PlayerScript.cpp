#include "PlayerScript.h"
#include <iostream>

PlayerScript::PlayerScript(RigidObject* ro){
	this->ro = ro;
}


PlayerScript::~PlayerScript() { }

void PlayerScript::run() { ro->move(x, y); }

 void PlayerScript::moveDown() {
	 ro->move(0,1);
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
	ro->move(x, y);

}
