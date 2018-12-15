#include "PlayerScript.h"

void myFunc() {
	std::cout << "Jag pekar!! " << std::endl;
}

PlayerScript::PlayerScript(GameObject* go){
	this->go = go;
	void(*fpek)() = myFunc;
	addInput<void> (SDLK_w, fpek);
}


PlayerScript::~PlayerScript()
{
}

 void PlayerScript::run(){
	 go->move(1, 1);
}