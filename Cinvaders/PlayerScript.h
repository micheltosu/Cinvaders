#ifndef PLAYER_SCRIPT_H
#define PLAYER_SCRIPT_H
#include "RigidObject.h"
#include "Script.h"
#include "GameObject.h"
#include <iostream>


using namespace ToMingine;
class PlayerScript : public Script
{
public:
	PlayerScript(RigidObject*);
	~PlayerScript();
	void run();
	void moveDown();
	void keyBoardEvent(Uint32);
private:
	RigidObject* ro;
};

#endif // !PLAYER_SCRIPT_H
