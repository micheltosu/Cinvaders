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

		std::vector<bool> mask1 = getMask(getSurface(), width, height);
		std::vector<bool>mask2 = getMask(ro->getSurface(), width, height);

		for (int b = 0; b <= mask1.size(); b++) {
			if (mask1.at(b) && mask2.at(b)) {
				std::cout << "Collision! ";
				return false;
			}
		}
		return true;
	}

	std::vector<bool> RigidObject::getMask(SDL_Surface* surf, int x, int y){
		std::vector<bool> mask(x*y);

		for (int row = 0; row <= surf->h; row++) {
			for (int p = 0; p < surf->w; p += surf->format->BitsPerPixel) {
				Uint32* pixels = static_cast<Uint32*>(surf->pixels);
				if (GetAlphaXY(surf,x,y)) {
					mask.push_back(false);
				}
				else {
					mask.push_back(true);
				}
			}
			for (int lastBit = x - surf->w; lastBit < x; lastBit++) {
				mask.push_back(false);
			}
		}
		return mask;
	}


	//https://stackoverflow.com/questions/28098164/alpha-value-of-pixel-color-and-per-pixel-collision-using-sdl
	int RigidObject::GetAlphaXY(SDL_Surface* surface, int x, int y){
		// get the specific pixel for checking the alpha value at x/y

		SDL_PixelFormat* pixelFormat = surface->format;
		int bpp = pixelFormat->BytesPerPixel;

		Uint8* p = (Uint8*)surface->pixels + y * surface->pitch + x * bpp;

		// ! here the game crashes
		Uint32 pixelColor = *p;

		// get the RGBA values

		Uint8 red, green, blue, alpha;

		// this function fails, sometimes the game crashes here
		SDL_GetRGBA(pixelColor, pixelFormat, &red, &green, &blue, &alpha);

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