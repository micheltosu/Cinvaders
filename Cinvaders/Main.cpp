#include <string>
#include <iostream>
#include "GameEngine.h"
#include "PlayerScript.h"
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
    RigidObject* player = new RigidObject(playerSprite, Type::PLAYER, 10, 10);
    RigidObject* enemy = new RigidObject("Resources/Image/ship.png", Type::ENEMY, 300, 300);
    PlayerScript* s = new PlayerScript(player);
    PlayerScript* s2 = new PlayerScript(enemy);

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
    
    player->addScript(s);
    myScene.addObject(player);
    myScene.addObject(enemy);

    ge.run();

    return 0;
}
