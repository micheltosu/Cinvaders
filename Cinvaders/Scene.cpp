#include "Scene.h"
#include "GameEngine.h"
#include <iostream>

namespace ToMingine {

Scene::Scene(){}

Scene::Scene(std::string bgPath){
	setBackground(bgPath);
}


Scene::~Scene(){}
void Scene::setBackground(std::string filename) {
	background = IMG_LoadTexture(GameEngine::getInstance().getRen(), filename.c_str());
	if (background == nullptr) {
		std::cout << "Error: cannot load image: " << filename << std::endl;
		std::cout << SDL_GetError() << std::endl;
		exit(-1);
	}
}
void Scene::addObject(GameObject * go){
	gameObjects.push_back(go);
}
bool Scene::run(){
	
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			GameEngine::getInstance().Quit();
			break;
		case SDL_KEYDOWN:
			if (key != event.key.keysym.sym) {
				key = event.key.keysym.sym;
				keysPressed++;
			}
			if (event.key.keysym.sym = SDLK_ESCAPE)
				return true;
				

			//keyMan->keyPressed(event.key.keysym.sym);
			break;
		case SDL_KEYUP:
			keysPressed--;
			if (keysPressed == 0)
				key = 0;

			//keyMan->keyReleased(event.key.keysym.sym);
			break;
		} // switch end
		
	} // event loop
	SDL_RenderClear(GameEngine::getInstance().getRen());
	SDL_RenderCopy(GameEngine::getInstance().getRen(), background, NULL, NULL);
	for (GameObject* go : gameObjects) {
		go->tick();
	}
	
	for (GameObject* go : gameObjects) {
		go->keyBoardEvent(key);
	}


	return false;
}
}
