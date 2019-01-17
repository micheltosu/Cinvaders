#include "RigidObject.h"
#include "GameEngine.h"
#include "Script.h"
#include <vector>

#define Maximum(a, b) ((a > b) ? a : b)
#define Minimum(a, b) ((a < b) ? a : b)

namespace ToMingine {
    RigidObject::RigidObject(Sprite* spr, Type t) : GameObject(spr, t) {};
    RigidObject::RigidObject(Sprite* spr, Type t, int x, int y) : GameObject(spr, t, x, y) {};
    RigidObject::RigidObject(std::string path, Type t): RigidObject(new Sprite(path), t) { }
    RigidObject::RigidObject(std::string path, Type t, int x, int y) : RigidObject(new Sprite(path), t, x, y) { }
    
    RigidObject::~RigidObject() { }

	void RigidObject::collision(Type t)	{ 
		script->collision(t);
	}

	bool RigidObject::pixelDetection(RigidObject * ro){
		int leftX = Maximum(rect.x, ro->getRect()->x);
		int leftY = Maximum(rect.y, ro->getRect()->y);
		int rightX = Minimum(rect.x + rect.w, ro->getRect()->x + ro->getRect()->w);
		int rightY = Minimum(rect.y + rect.h, ro->getRect()->y + ro->getRect()->h);


		int width = rightX - leftX;
		int height = rightY - leftY;

		SDL_Rect collisionRect = { leftX, leftY, width, height };

		int o1XOffset = Maximum(collisionRect.x, rect.x) - Minimum(collisionRect.x, rect.x);
		int o1YOffset = Maximum(collisionRect.y, rect.y) - Minimum(collisionRect.y, rect.y);
		int o2XOffset = Maximum(collisionRect.x, ro->getRect()->x) - Minimum(collisionRect.x, ro->getRect()->x);
		int o2YOffset = Maximum(collisionRect.y, ro->getRect()->y) - Minimum(collisionRect.y, ro->getRect()->y);

		for (int r = 0; r < collisionRect.h; r++) {
			for (int c = 0; c < collisionRect.w; c++) {
				int o1A = GetAlphaXY(c + o1XOffset, r + o1YOffset);
				int o2A = ro->GetAlphaXY(c + o2XOffset, r + o2YOffset);
				if (o1A&&o2A)
					return true;
			}
		}
		return false;
	}

	//std::vector<bool> RigidObject::getMask(SDL_Surface* surf, int x, int y){
	//	std::vector<bool> mask(x*y);

	//	for (int row = 0; row <= surf->h; row++) {
	//		for (int p = 0; p < surf->w; p += surf->format->BitsPerPixel) {
	//			Uint32* pixels = static_cast<Uint32*>(surf->pixels);
	//			if (GetAlphaXY(surf,x,y)) {
	//				mask.push_back(false);
	//			}
	//			else {
	//				mask.push_back(true);
	//			}
	//		}
	//		for (int lastBit = x - surf->w; lastBit < x; lastBit++) {
	//			mask.push_back(false);
	//		}
	//	}
	//	return mask;
	//}


	int RigidObject::GetAlphaXY(int x, int y){
		
		unsigned long int pixel = dynamic_cast<Sprite*>(renOb)->getPixel(x, y);

		Uint8 red, green, blue, alpha;

		SDL_GetRGBA(pixel, getSurface()->format, &red, &green, &blue, &alpha);

		return alpha;
	}


    GameObject* RigidObject::requestMove(int x, int y){
        SDL_Rect* otherRect;
        std::list<GameObject*>* gameObjects = GameEngine::getInstance().getCurrentScene()->getGameObjects();
        for (GameObject* go : *gameObjects) {
            otherRect = go->getRect();
            if (go != this && type != go->getType()) {
                if (
                    otherRect->y + otherRect->h >= getRect()->y + y &&
                    getRect()->y + otherRect->h + y >= otherRect->y &&
                    otherRect->x + otherRect->w >= getRect()->x + x &&
                    getRect()->x + getRect()->w + x >= otherRect->x 
                    ) {
					RigidObject* ro;
					if (ro = dynamic_cast<RigidObject*>(go)) {
						if (pixelDetection(ro)) {
							collision(go->getType());
								if (go->hasScript())
									go->collision(type);
								return go;
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
		if (requestMove(x, y)) {
			rect.x += x * SPEED;
			rect.y += y * SPEED;
		}
    }
}