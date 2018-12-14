#include "PlayerScript.h"

PlayerScript::PlayerScript(GameObject* go){
	this->go = go;
}


PlayerScript::~PlayerScript()
{
}

 void PlayerScript::run(){
	 go->move(1, 1);
}