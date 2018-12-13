#include "PlayerScript.h"

PlayerScript::PlayerScript(GameObject* go){
	this->go = go;
}


PlayerScript::~PlayerScript()
{
}

void PlayerScript::keyBoardEvent(char input){
	if (input == 'w')
		std::cout << "Pressed W." << std::endl;
	}
}
