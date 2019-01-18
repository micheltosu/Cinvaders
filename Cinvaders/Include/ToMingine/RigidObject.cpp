#include "RigidObject.h"
#include "GameEngine.h"
#include "Script.h"
#include <vector>

#define Maximum(a, b) ((a > b) ? a : b)
#define Minimum(a, b) ((a < b) ? a : b)

namespace ToMingine {
    RigidObject::RigidObject(Sprite* spr, Type t) : GameObject(spr, t) {};
    RigidObject::RigidObject(Sprite* spr, Type t, int x, int y) : GameObject(spr, t, x, y) {};
    RigidObject::~RigidObject() { }
    
    RigidObject* RigidObject::create(Sprite *spr, Type t, int x, int y) {
        return new RigidObject(spr, t, x, y);
    }

	void RigidObject::collision(Type t)	{ 
		if(script != nullptr)
			script->collision(t);
	}

	bool RigidObject::pixelDetection(RigidObject * ro, int movex, int movey, Direction& dir){
		int leftX = Maximum(rect.x+movex, ro->getRect()->x);
		int leftY = Maximum(rect.y+movey, ro->getRect()->y);
		int rightX = Minimum(rect.x + rect.w + movex, ro->getRect()->x + ro->getRect()->w);
		int rightY = Minimum(rect.y + rect.h + movey, ro->getRect()->y + ro->getRect()->h);


		int width = rightX - leftX;
		int height = rightY - leftY;

		SDL_Rect collisionRect = { leftX, leftY, width, height };

		int o1XOffset = Maximum(collisionRect.x, rect.x+movex) - Minimum(collisionRect.x, rect.x+movex);
		int o1YOffset = Maximum(collisionRect.y, rect.y+movey) - Minimum(collisionRect.y, rect.y+movey);
		int o2XOffset = Maximum(collisionRect.x, ro->getRect()->x) - Minimum(collisionRect.x, ro->getRect()->x);
		int o2YOffset = Maximum(collisionRect.y, ro->getRect()->y) - Minimum(collisionRect.y, ro->getRect()->y);


		for (int r = 0; r < collisionRect.h; r++) {
			for (int c = 0; c < collisionRect.w; c++) {
				int o1A = GetAlphaXY(c + o1XOffset, r + o1YOffset);
				int o2A = ro->GetAlphaXY(c + o2XOffset, r + o2YOffset);
				if (o1A && o2A) {
					//if((o1s pixel till vänster||o1s pixel till höger)&&
					//	(!o1s pixel ovan || !o1 pixel under);
					if ((GetAlphaXY(c - 1 + o1XOffset, r + o1YOffset) || GetAlphaXY(c + 1 + o1XOffset, r + o1YOffset))
						&&(!(GetAlphaXY(c + o1XOffset, r -1 + o1YOffset)) || !(GetAlphaXY(c + o1XOffset, r + 1 + o1YOffset)))){
						//std::cout << "vert! ";
						dir = VERT;
					}
					/*if ((!(GetAlphaXY(c - 1 + o1XOffset, r + o1YOffset)) || !(GetAlphaXY(c + 1 + o1XOffset, r + o1YOffset)))
						&& (GetAlphaXY(c + o1XOffset, r - 1 + o1YOffset) || GetAlphaXY(c + o1XOffset, r + 1 + o1YOffset))) */
					else {
						//std::cout << "horiz! ";
						dir = HORIZ;
					}

					return true;
				}
			}
		}
		return false;
	}

	int RigidObject::GetAlphaXY(int x, int y){
		
		unsigned long int pixel = dynamic_cast<Sprite*>(renOb)->getPixel(x, y);

		Uint8 red, green, blue, alpha;

		SDL_GetRGBA(pixel, getSurface()->format, &red, &green, &blue, &alpha);

		return alpha;
	}


    GameObject* RigidObject::requestMove(int& x, int& y, Direction& dir){
        SDL_Rect* otherRect;
        std::list<GameObject*>* gameObjects = GameEngine::getInstance().getCurrentScene()->getGameObjects();
        for (GameObject* go : *gameObjects) {
            otherRect = go->getRect();
            if (go != this && type != go->getType()) {
                if (
                    otherRect->y + otherRect->h >= getRect()->y + y &&
                    getRect()->y + getRect()->h + y >= otherRect->y &&
                    otherRect->x + otherRect->w >= getRect()->x + x &&
                    getRect()->x + getRect()->w + x >= otherRect->x 
                    ) {
					RigidObject* ro;
					if (ro = dynamic_cast<RigidObject*>(go)) {
						if (pixelDetection(ro, x, y,dir)) {
							if (ro->type == WALL) {
								move(x, 0);
							}

							collision(ro->getType());
							if (ro->hasScript()) {
								std::cout << ro->getType() << std::endl;
								ro->collision(type);
								}
								return ro;
						}
					}
                }
            }
        }
		rect.x += x * SPEED;
		rect.y += y * SPEED;
        return nullptr;
    }

    void RigidObject::move(int x, int y) {        
			rect.x += x * SPEED;
			rect.y += y * SPEED;
    }
}
