#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "RenderedObject.h"
#include <string>

namespace ToMingine {

class GameObject {
    public:
		GameObject(std::string);
		~GameObject();
		void tick();
		int width, height;

    private:
		void draw();
		SDL_Rect rect;
		SDL_Renderer* renderer;
		SDL_Texture* texture;
		

	};
}
#endif