#include "PlayerScript.h"
#include <iostream>

PlayerScript::PlayerScript(GameObject* go){
	this->go = go;
}


PlayerScript::~PlayerScript()
{
}

 void PlayerScript::run(){
}

 void PlayerScript::moveDown(){
	 go->move(0,1);
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
	go->move(x, y);

}
