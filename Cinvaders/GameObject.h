#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "RenderedObject.h"
#include <string>
#include "Script.h"

namespace ToMingine {

class GameObject {
    public:
		GameObject(std::string);
		~GameObject();

		void addScript(Script* s) { script = s; }
		void tick(SDL_Event&);
		void move(int x, int y);

    private:
		void draw();
		int width, height;

		Script* script = nullptr;
		SDL_Rect rect;
		SDL_Renderer* renderer;
		SDL_Texture* texture;
		

	};
}
#endif