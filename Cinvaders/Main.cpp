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
	ge.setBackground("Resources/Image/background.png");

	RigidObject* player = new RigidObject("Resources/Image/ship.png");
	RigidObject* enemy = new RigidObject("Resources/Image/ship.png", 300, 300);
	PlayerScript* s = new PlayerScript(player);
	PlayerScript* s2 = new PlayerScript(enemy);

	player->addScript(s);
	//enemy->addScript(s2);
	ge.add(player);
	ge.add(enemy);

  SDL_Keycode sk = SDLK_SPACE;
  ge.keyboardManager()->addBinding(sk, printer);
    
	ge.remove(enemy);//testar bara remove func.
	ge.add(enemy);

	ge.run();

    return 0;
}
