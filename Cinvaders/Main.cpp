#include <string>
#include <iostream>
#include "GameEngine.h"
#include "PlayerScript.h"
#include "EnemyScript.h"
#include "AnimatedSprite.h"
#include "FunctionKeybinding.h"
#include "MemberFunctionKeybinding.h"
#include "Inputfield.h"
#include "TextLabel.h"
#include "Button.h"

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
	
	PhysicsObject* player = new PhysicsObject(playerSprite, PLAYER, 500, 550);
	RigidObject* enemy = new RigidObject(new AnimatedSprite("Resources/Image/blueShipSheet.png", 4, 1), ENEMY, 300, 30);
	RigidObject* enemy2 = new RigidObject(new AnimatedSprite("Resources/Image/blueShipSheet.png", 4, 1), ENEMY, 300, 200);
	RigidObject* enemy3 = new RigidObject(new AnimatedSprite("Resources/Image/blueShipSheet.png", 4, 1), ENEMY, 600, 200);
	RigidObject* enemy4 = new RigidObject(new AnimatedSprite("Resources/Image/blueShipSheet.png", 4, 1), ENEMY, 700, 200);
	RigidObject* wall = new RigidObject(new AnimatedSprite("Resources/Image/wall.png", 5, 1), WALL, 0, 644);
	RigidObject* sidewall = new RigidObject(new AnimatedSprite("Resources/Image/sidewall.png", 5, 1), WALL, 1, 0);

    PlayerScript* ps = new PlayerScript(player);
	player->addScript(ps);
	enemy->addScript(new EnemyScript(enemy));
	enemy2->addScript(new EnemyScript(enemy2));
	enemy3->addScript(new EnemyScript(enemy3));
	enemy4->addScript(new EnemyScript(enemy4));
	myScene.addObject(player);
	myScene.addObject(enemy);
	myScene.addObject(enemy2);
	myScene.addObject(enemy3);
	myScene.addObject(enemy4);
	myScene.addObject(wall);
	myScene.addObject(sidewall);

    // Keybindings
    SDL_Keycode sk = SDLK_SPACE;
    MemberFunctionKeybinding<PlayerScript>* mk = new MemberFunctionKeybinding<PlayerScript>(ps, &PlayerScript::shoot);
    GameEngine::getInstance().keyboardManager()->addBinding(sk, mk);
    
    GameEngine::getInstance().keyboardManager()->addListener(player);
    // End keybindings
    
    
    // TextBox
    Inputfield* inField = new Inputfield("Resources/Fonts/Pixeled.ttf", 15, 100,100,200,50);
    myScene.addObject(inField);
    
    // TextLabel
    TextLabel* txtLbl = new TextLabel("Resources/Fonts/Pixeled.ttf", 20, 300, 75, 300, 50);
    txtLbl->setText("C Invaders");
    myScene.addObject(txtLbl);
    
    
    //Button
    SDL_Color fgColor = {71,255,39,255};
    SDL_Color bgColor = {0,0,0,255};
    auto buttonFunk = []()->void{ std::cout << "I WAS HIT!" << std::endl; };
    SDL_Rect btnPos = {900,550,100,50};
    Button btn("Resources/Fonts/Pixeled.ttf", "Click me!", buttonFunk ,btnPos);
    btn.setFgColor(fgColor);
    btn.setBgColor(bgColor);
    myScene.addObject(&btn);
    
    ge.run();
    return 0;
}
