#include <string>
#include <iostream>
#include "GameEngine.h"
#include "PlayerScript.h"
#include "EnemyScript.h"
#include "AnimatedSprite.h"
#include "FunctionKeybinding.h"
#include "MemberFunctionKeybinding.h"

using namespace std;
using namespace ToMingine;

int main(int argc, char** argv) {
    int window_width = 1280;
    int window_height = 720;

    GameEngine &ge = GameEngine::getInstance();
    Scene myScene = Scene("Resources/Image/background.png");
    Scene myScene2 = Scene("Resources/Image/background.png");
    ge.addScene(&myScene);
    ge.addScene(&myScene2);

	AnimatedSprite* playerSprite = new AnimatedSprite("Resources/Image/blueShipSheet.png", 4, 1);
	RigidObject* player = new RigidObject(playerSprite, PLAYER, 500, 550);
	RigidObject* enemy = new RigidObject(new AnimatedSprite("Resources/Image/blueShipSheet.png", 4, 1), ENEMY, 300, 30);
	RigidObject* enemy2 = new RigidObject(new AnimatedSprite("Resources/Image/blueShipSheet.png", 4, 1), ENEMY, 300, 200);
	RigidObject* enemy3 = new RigidObject(new AnimatedSprite("Resources/Image/blueShipSheet.png", 4, 1), ENEMY, 600, 200);
	RigidObject* enemy4 = new RigidObject(new AnimatedSprite("Resources/Image/blueShipSheet.png", 4, 1), ENEMY, 700, 200);

    PlayerScript* ps = new PlayerScript(player);
	player->addScript(ps);
	enemy->addScript(new EnemyScript(enemy));
	enemy2->addScript(new EnemyScript(enemy2));
	enemy3->addScript(new EnemyScript(enemy3));
	enemy4->addScript(new EnemyScript(enemy4));
	myScene.addObject(player);
	//myScene.addObject(enemy);
	myScene.addObject(enemy2);
	//myScene.addObject(enemy3);
	myScene.addObject(enemy4);

    // Keybindings
    SDL_Keycode sk = SDLK_SPACE;
    MemberFunctionKeybinding<PlayerScript>* mk = new MemberFunctionKeybinding<PlayerScript>(ps, &PlayerScript::shoot);
    GameEngine::getInstance().keyboardManager()->addBinding(sk, mk);
    
    // End keybindings
    
    
    ge.run();

    return 0;
}
