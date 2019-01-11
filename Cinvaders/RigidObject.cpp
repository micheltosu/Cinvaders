#include "RigidObject.h"
#include "GameEngine.h"
#include "Script.h"

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
		std::cout << width << ":" << height << std::endl;

		int size = (width * height) % 8 == 0? (width * height) / 8 : ((width * height) / 8) + 1;
		Uint8* area = new Uint8[size];

		return false;
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