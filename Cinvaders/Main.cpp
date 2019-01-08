#include <string>
#include <iostream>
#include "GameEngine.h"
#include "PlayerScript.h"
#include "EnemyScript.h"

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

	RigidObject* player = new RigidObject("Resources/Image/ship.png", PLAYER, 600, 700);
	RigidObject* enemy = new RigidObject("Resources/Image/ship.png", ENEMY, 300, 300);
	RigidObject* enemy2 = new RigidObject("Resources/Image/ship.png", ENEMY, 300, 400);
	RigidObject* enemy3 = new RigidObject("Resources/Image/ship.png", ENEMY, 300, 500);
	RigidObject* enemy4 = new RigidObject("Resources/Image/ship.png", ENEMY, 400, 300);

	player->addScript(new PlayerScript(player));
	enemy->addScript(new EnemyScript(enemy));
	enemy2->addScript(new EnemyScript(enemy2));
	enemy3->addScript(new EnemyScript(enemy3));
	enemy4->addScript(new EnemyScript(enemy4));
	myScene.addObject(player);
	myScene.addObject(enemy);
	myScene.addObject(enemy2);
	myScene.addObject(enemy3);
	myScene.addObject(enemy4);

	SDL_Keycode sk = SDLK_SPACE;
	ge.keyboardManager()->addBinding(sk, printer);
    

	ge.run();

    return 0;
}
