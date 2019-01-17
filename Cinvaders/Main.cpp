#include <string>
#include <iostream>

#include "ToMingine.h"

#include "PlayerScript.h"
#include "EnemyScript.h"

using namespace std;
using namespace ToMingine;

int main(int argc, char** argv) {
    GameEngine &ge = GameEngine::getInstance();
    
    // Common things
    SDL_Color transparent = {0,0,0,0};
    SDL_Color fgColor = {71,255,39,0};
    SDL_Color bgColor = {0,0,0,255};
    
    TextLabel *playerName = new TextLabel("Resources/Fonts/Pixeled.ttf",15, 25, 25, 0,0);
    playerName->setBgColor(transparent);
    playerName->setFgColor(fgColor);
    playerName->setText("anonymous");
    
    
    // Create scenes
    Scene mainMenu = Scene("Resources/Image/bgMenu.png");
    ge.addScene(&mainMenu);
    

    // Add main menu objects
    TextLabel *gameLabel = new TextLabel("Resources/Fonts/Pixeled.ttf",40, 400, 50, 600, 100);
    gameLabel->setBgColor(transparent);
    gameLabel->setFgColor(fgColor);
    gameLabel->setText("C INVADERS");
    
    TextLabel *tagline = new TextLabel("Resources/Fonts/Pixeled.ttf",20, 200, 200 , 0,0);
    tagline->setBgColor(transparent);
    tagline->setFgColor(fgColor);
    tagline->setText("Defend your language against the invasion");
    
    TextLabel *nameInstructions = new TextLabel("Resources/Fonts/Pixeled.ttf",15, 200, 300, 0,0);
    nameInstructions->setBgColor(transparent);
    nameInstructions->setFgColor(fgColor);
    nameInstructions->setText("Click in the box to enter player name:");
    
    Inputfield *nameInput = new Inputfield("Resources/Fonts/Pixeled.ttf", 15, 700,300,0,0);
    nameInput->setFgColor(fgColor);
    nameInput->setBgColor(bgColor);
    nameInput->setText("Player 1");
    
    SDL_Rect buttonPos = {500,500,100,100};
    auto updateNameLabel = []() -> void {
        GameEngine::getInstance().nextScene();
        
    };
    
    Button *startButton = new Button("Resources/Fonts/Pixeled.ttf", "Click to play", updateNameLabel, buttonPos, 20);
    startButton->setFgColor(fgColor);
    startButton->setBgColor(bgColor);
    
    
    TextLabel *instructions = new TextLabel("Resources/Fonts/Pixeled.ttf",15, 380, 650, 0,0);
    instructions->setBgColor(transparent);
    instructions->setFgColor(fgColor);
    instructions->setText("Move with the WASD keys, shoot with SPACEBAR");
    
    
    
    mainMenu.addObject(gameLabel);
    mainMenu.addObject(tagline);
    mainMenu.addObject(nameInstructions);
    mainMenu.addObject(startButton);
    mainMenu.addObject(nameInput);
    mainMenu.addObject(instructions);
    
    
    //
    // First level
    //
    
    Scene level1 = Scene("Resources/Image/background.png");
    ge.addScene(&level1);
    level1.addObject(playerName);
    
    //Add Scene objects
    AnimatedSprite* playerSprite = new AnimatedSprite("Resources/Image/blueShipSheet.png", 4, 1);
    
    PhysicsObject* player = new PhysicsObject(playerSprite, PLAYER, 500, 550);
	


    PlayerScript* ps = new PlayerScript(player);
    player->addScript(ps);
    MemberFunctionKeybinding<PlayerScript>* mk = new MemberFunctionKeybinding<PlayerScript>(ps, &PlayerScript::shoot);
    level1.addObject(player);
    
    
    RigidObject* enemy1 = new RigidObject(new AnimatedSprite("Resources/Image/blueShipSheet.png", 4, 1), ENEMY, 100, 50);
    enemy1->addScript(new EnemyScript(enemy1));
    level1.addObject(enemy1);
    
    RigidObject* enemy2 = new RigidObject(new AnimatedSprite("Resources/Image/blueShipSheet.png", 4, 1), ENEMY, 250, 100);
    enemy2->addScript(new EnemyScript(enemy2));
    level1.addObject(enemy2);
    
    RigidObject* enemy3 = new RigidObject(new AnimatedSprite("Resources/Image/blueShipSheet.png", 4, 1), ENEMY, 400, 50);
    enemy3->addScript(new EnemyScript(enemy3));
    level1.addObject(enemy3);
    
    RigidObject* enemy4 = new RigidObject(new AnimatedSprite("Resources/Image/blueShipSheet.png", 4, 1), ENEMY, 550, 100);
    enemy4->addScript(new EnemyScript(enemy4));
    level1.addObject(enemy4);
    
    RigidObject* enemy5 = new RigidObject(new AnimatedSprite("Resources/Image/blueShipSheet.png", 4, 1), ENEMY, 700, 50);
    enemy5->addScript(new EnemyScript(enemy5));
    level1.addObject(enemy5);
    
    RigidObject* enemy6 = new RigidObject(new AnimatedSprite("Resources/Image/blueShipSheet.png", 4, 1), ENEMY, 850, 100);
    enemy6->addScript(new EnemyScript(enemy6));
    level1.addObject(enemy6);
    
    RigidObject* enemy7 = new RigidObject(new AnimatedSprite("Resources/Image/blueShipSheet.png", 4, 1), ENEMY, 1000, 50);
    enemy7->addScript(new EnemyScript(enemy7));
    level1.addObject(enemy7);
    
    


    // Keybindings
    SDL_Keycode sk = SDLK_SPACE;

    GameEngine::getInstance().keyboardManager()->addBinding<PlayerScript>(sk, mk);
    GameEngine::getInstance().keyboardManager()->addListener(player);
    // End keybindings
    
    
    
    ge.run();
    return 0;
}
