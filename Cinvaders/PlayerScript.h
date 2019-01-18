#ifndef PLAYER_SCRIPT_H
#define PLAYER_SCRIPT_H

#include <iostream>
#include "ToMingine.h"

using namespace ToMingine;
class PlayerScript : public Script {

public:
	PlayerScript(PhysicsObject*);
	~PlayerScript();
	void run();
	void moveUp();
    void keyBoardEvent(const SDL_KeyboardEvent&) override;
	void collision(Type t);
	void shoot(uint32_t);
    GameObject* getGameObject() override { return ro; }
    
	int x = 0, y = 0;

private:
	SDL_Rect prePos;
	PhysicsObject* ro;
};

#endif // !PLAYER_SCRIPT_H
