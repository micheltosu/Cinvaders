#include "PlayerScript.h"
#include "BulletScript.h"
PlayerScript::PlayerScript(PhysicsObject* ro){
	this->ro = ro;
	ro->setElasticity(1);
}

PlayerScript::~PlayerScript() { }

void PlayerScript::run() {
		
	if (ro->getRect()->x > GameEngine::getInstance().window_width)
		ro->getRect()->x = 0 - ro->getRect()->w;
	if (ro->getRect()->x < 0 - ro->getRect()->w)
		ro->getRect()->x = GameEngine::getInstance().window_width;
	if (ro->getRect()->y > GameEngine::getInstance().window_height)
		ro->getRect()->y = 0 - ro->getRect()->h;
	if (ro->getRect()->y < 0 - ro->getRect()->h)
		ro->getRect()->y = GameEngine::getInstance().window_height;
	prePos = *ro->getRect();
	ro->requestMove(&x, &y); 

}
void PlayerScript::keyBoardEvent(const SDL_KeyboardEvent& kev) {
    if (kev.keysym.sym == SDLK_s)
        y += 1;
    if (kev.keysym.sym == SDLK_w)
        y -= 5;
    if (kev.keysym.sym == SDLK_d)
        x += 1;
    if (kev.keysym.sym == SDLK_a)
        x -= 1;
    if (kev.keysym.sym == SDLK_q) {
        if (x > 0) x--;
        if (x < 0) x++;
        if (y > 0) y--;
        if (y < 0) y++;
    }
};


void PlayerScript::collision(Type t) {
	
}


void PlayerScript::shoot(Uint32){
	int x = ro->getRect()->x +(ro->getRect()->w / 2);
	int y = ro->getRect()->y -(ro->getRect()->h / 2);
    RigidObject* bullet = RigidObject::create(new Sprite("Resources/Image/laser.png"), PLAYER, x-1, y);
	bullet->addScript(new BulletScript(1, bullet));
	GameEngine::getInstance().getCurrentScene()->addObject(bullet);
}

void PlayerScript::moveUp() {
	std::cout << "HEJ!" << std::endl;
}
