#include "RigidObject.h"
#include "GameEngine.h"
#include "Script.h"
#include <vector>

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
		int smallestX = rect.x < ro->getRect()->x ? rect.x : ro->getRect()->x;
		int smallestY = rect.y < ro->getRect()->y ? rect.y : ro->getRect()->y;
		int biggestH = rect.y + rect.h > ro->getRect()->y + ro->getRect()->h ? rect.y + rect.h : ro->getRect()->y + ro->getRect()->h;
		int biggestW = rect.y + rect.w > ro->getRect()->y + ro->getRect()->w ? rect.y + rect.w : ro->getRect()->y + ro->getRect()->w;

		int width = biggestW - smallestX;
		int height = biggestH - smallestY;

		int thisX = rect.x - smallestX;
		int thisY = rect.y - smallestY;
		int otherX = ro->getRect()->x - smallestX;
		int otherY = ro->getRect()->y - smallestY;

		int size = width * height;
		std::vector<bool> area(size);
		std::vector<bool> mask1 = getMask(getSurface(), width, height);
		std::vector<bool> mask2 = getMask(ro->getSurface(), width, height);
		



		return false;
	}

	std::vector<bool> RigidObject::getMask(SDL_Surface* surf, int x, int y){
		std::vector<bool> mask(x*y);
		for (int row = 0; row <= surf->h; row++) {
			int column = 0;
			for (int pixel = 0; pixel < surf->w; pixel += surf->format->BitsPerPixel) {
				if (surf->format->BitsPerPixel) {
					Uint32* pixels = static_cast<Uint32*>(surf->pixels);
					if (pixels[row + 1 * pixel] & surf->format->Amask) {
						mask[column*row] = 1;
					}
					else {
						mask[column*row] = 0;
					}
				}
			}
			//förskjut sista biten.
				column++;
		}
		
		
		return std::vector<bool>();
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