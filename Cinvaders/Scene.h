#ifndef SCENE_H
#define SCENE_H

#ifdef _WIN32

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#elif defined (__APPLE__)
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <SDL2_ttf/SDL_ttf.h>
#endif

#include <list>
#include "GameObject.h"

namespace ToMingine {
class Scene{
public:
	Scene();
	Scene(std::string);
	~Scene();
	void setBackground(std::string path);
	void addObject(GameObject* go);
	//remove object
	bool run();

private:
	SDL_Texture *background;
	std::list<GameObject*> gameObjects;
	Uint32 key = 0;
	int keysPressed = 0;

};
}

#endif // !SCENE_H