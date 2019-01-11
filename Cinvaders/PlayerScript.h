#ifndef PLAYER_SCRIPT_H
#define PLAYER_SCRIPT_H
#include "RigidObject.h"
#include "Script.h"
#include "GameObject.h"
#include <iostream>


using namespace ToMingine;
class PlayerScript : public Script {

public:
	PlayerScript(PhysicsObject*);
	~PlayerScript();
	void run();
	void moveUp();
    void keyBoardEvent(Uint32);
	void collision(Type t);
	void shoot(uint32_t);
	int x = 0, y = 0;

private:
	SDL_Rect prePos;
	PhysicsObject* ro;
};

#endif // !PLAYER_SCRIPT_H
