#include "PlayerScript.h"
#include <iostream>

PlayerScript::PlayerScript(GameObject* go){
	this->go = go;
}


PlayerScript::~PlayerScript()
{
}

 void PlayerScript::run(){
	 //go->move(0, 1);
}

 void PlayerScript::moveDown(){
	 go->move(0,1);
 }

void PlayerScript::keyBoardEvent(Uint32 key){
	std::cout << "keyboardevent";
	if (key == SDLK_s)
		 moveDown();
}
