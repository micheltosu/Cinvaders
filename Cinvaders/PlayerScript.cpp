#include "PlayerScript.h"
#include <iostream>

PlayerScript::PlayerScript(RigidObject* ro){
	this->ro = ro;
}


PlayerScript::~PlayerScript()
{
}

 void PlayerScript::run(){
}

 void PlayerScript::moveDown(){
	 ro->move(0,1);
 }

void PlayerScript::keyBoardEvent(Uint32 key){
	int x = 0, y = 0;
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
