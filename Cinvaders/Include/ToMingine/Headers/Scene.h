#ifndef SCENE_H
#define SCENE_H

#ifdef _WIN32

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#elif defined (__APPLE__)
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#endif

#include <list>
#include "GameObject.h"
#include "KeyboardManager.h"
#include "MouseManager.h"

namespace ToMingine {
class Scene{
public:
	Scene();
	Scene(std::string);
	~Scene();
	void setBackground(std::string path);
	void addObject(GameObject* go);
	void removeObject(GameObject* go);
	bool run();
    void draw();
	std::list<GameObject*> *getGameObjects() { return &gameObjects; }
private:
	SDL_Texture *background;
	std::list<GameObject*> gameObjects;
	std::list<GameObject*> toRemove;
	Uint32 key = 0;
	int keysPressed = 0;
    KeyboardManager* keyMan;
    MouseManager* mouseMan;

};
}

#endif // !SCENE_H
