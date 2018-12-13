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

		void addScript(Script s) { script = s; }
		void tick(SDL_Event&);
		int width, height;

    private:
		void draw();

		Script* script;
		SDL_Rect rect;
		SDL_Renderer* renderer;
		SDL_Texture* texture;
		

	};
}
#endif