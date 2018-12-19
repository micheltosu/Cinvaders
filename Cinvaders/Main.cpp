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

	GameEngine gm = GameEngine::getInstance();
	gm.setBackground("Resources/Image/background.png");

	GameObject* go = new GameObject("Resources/Image/ship.png");
	PlayerScript* s = new PlayerScript(go);
	go->addScript(s);
	gm.add(go);
	gm.run();
    
    SDL_Keycode sk = SDLK_SPACE;
    gm.keyboardManager()->addBinding(sk, printer);


	return 0;
}
