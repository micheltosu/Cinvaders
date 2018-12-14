#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "RenderedObject.h"
#include "Script.h"
#include "Input.h"
#include <string>
#include <vector>

namespace ToMingine {

class GameObject {
    public:
		GameObject(std::string);
		~GameObject();

		void addScript(Script* s) { script = s; }
		void tick(SDL_Event&);
		void move(int x, int y);
		void addInput(Input i);

		

    private:

		void runInput(unsigned int key);
		void draw();

		std::vector<Input> inputs;
		int width, height;

		Script* script = nullptr;
		SDL_Rect rect;
		SDL_Renderer* renderer;
		SDL_Texture* texture;
		

	};
}
#endif