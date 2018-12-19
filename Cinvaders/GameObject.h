#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include <vector>
#include "Script.h"


namespace ToMingine {

class GameObject {
    public:
		GameObject(std::string);
		GameObject(std::string, int x, int y);
		~GameObject();

		void addScript(Script* s) { script = s; }
		void tick();
		void keyBoardEvent(Uint32);
		void move(int x, int y);

		SDL_Rect* getRect() { return &rect; }

	protected:
		SDL_Rect rect;
    

private:
		void draw();
		
		int width, height;

		Script* script = nullptr;
		SDL_Renderer* renderer;
		SDL_Texture* texture;
		

	};
}
#endif