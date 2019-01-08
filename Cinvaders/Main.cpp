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

    SDL_Keycode sk = SDLK_SPACE;
    SDL_Keycode right = SDLK_d;
    SDL_Keycode left = SDLK_a;
    SDL_Keycode up = SDLK_w;
    SDL_Keycode down = SDLK_s;
    
    MemberFunctionKeybinding<PlayerScript>* mk = new MemberFunctionKeybinding<PlayerScript>(s, &PlayerScript::shoot);
    MemberFunctionKeybinding<PlayerScript>* player_move = new MemberFunctionKeybinding<PlayerScript>(s, &PlayerScript::move);
    
    GameEngine::getInstance().keyboardManager()->addBinding(sk, mk);
    GameEngine::getInstance().keyboardManager()->addBinding(right, player_move);
    GameEngine::getInstance().keyboardManager()->addBinding(left, player_move);
    GameEngine::getInstance().keyboardManager()->addBinding(up, player_move);
    GameEngine::getInstance().keyboardManager()->addBinding(down, player_move);
    
	AnimatedSprite* playerSprite = new AnimatedSprite("Resources/Image/blueShipSheet.png", 4, 1);
	RigidObject* player = new RigidObject(playerSprite, PLAYER, 600, 700);
	RigidObject* enemy = new RigidObject(new AnimatedSprite("Resources/Image/blueShipSheet.png", 4, 1), ENEMY, 300, 300);
	RigidObject* enemy2 = new RigidObject(new AnimatedSprite("Resources/Image/blueShipSheet.png", 4, 1), ENEMY, 300, 400);
	RigidObject* enemy3 = new RigidObject(new AnimatedSprite("Resources/Image/blueShipSheet.png", 4, 1), ENEMY, 300, 500);
	RigidObject* enemy4 = new RigidObject(new AnimatedSprite("Resources/Image/blueShipSheet.png", 4, 1), ENEMY, 400, 300);

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


    ge.run();

    return 0;
}
