#include <string>
#include <iostream>
#include "GameEngine.h"
#include "PlayerScript.h"

using namespace std;
using namespace ToMingine;

void printer() {
    cout << "JUMP" << endl;
}

int main(int argc, char** argv) {
    int window_width = 1280;
    int window_height = 720;

	GameEngine &ge = GameEngine::getInstance();
	Scene myScene = Scene("Resources/Image/background.png");
	Scene myScene2 = Scene("Resources/Image/background.png");
	ge.addScene(&myScene);
	ge.addScene(&myScene2);

	RigidObject* player = new RigidObject("Resources/Image/ship.png");
	RigidObject* enemy = new RigidObject("Resources/Image/ship.png", 300, 300);
	PlayerScript* s = new PlayerScript(player);
	PlayerScript* s2 = new PlayerScript(enemy);

	player->addScript(s);
	myScene.addObject(player);
	myScene2.addObject(enemy);

	SDL_Keycode sk = SDLK_SPACE;
	ge.keyboardManager()->addBinding(sk, printer);
    

	ge.run();

    return 0;
}
