#include <string>
#include <iostream>
#include "GameEngine.h"
#include "PlayerScript.h"

using namespace std;
using namespace ToMingine;
int main(int argc, char** argv) {
	int window_width = 1280;
	int window_height = 720;

	GameEngine gm = GameEngine::getInstance();
	gm.setBackground("Resources/Image/background.png");

	RigidObject* player = new RigidObject("Resources/Image/ship.png", 10, 10);
	PlayerScript* s = new PlayerScript(player);
	player->addScript(s);
	gm.add(player);
	gm.run();


	return 0;
}