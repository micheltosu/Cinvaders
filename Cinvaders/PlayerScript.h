#ifndef PLAYER_SCRIPT_H
#define PLAYER_SCRIPT_H
#include "GameEngine.h"
#include "Script.h"
#include "GameObject.h"
#include <iostream>


using namespace ToMingine;
class PlayerScript : public Script
{
public:
	PlayerScript(GameObject*);
	~PlayerScript();
	void run();
	//void keyBoardEvent(char);

private:
	GameObject* go;
};

#endif // !PLAYER_SCRIPT_H
