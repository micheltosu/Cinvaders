#include "GameObject.h"
#include "GameEngine.h"


namespace ToMingine {
	
	GameObject::GameObject(std::string path) {
		renderer = GameEngine::getInstance()->getRen();
		SDL_Surface* surface = IMG_Load(path.c_str());
		texture = SDL_CreateTextureFromSurface(renderer, surface);
		rect = { 0, 0, surface->w, surface->h };
		SDL_FreeSurface(surface);
	}

	GameObject::GameObject(std::string path, int x, int y){
		renderer = GameEngine::getInstance()->getRen();
		SDL_Surface* surface = IMG_Load(path.c_str());
		texture = SDL_CreateTextureFromSurface(renderer, surface);
		rect = { x, y, surface->w, surface->h };
		SDL_FreeSurface(surface);
	}

	GameObject::~GameObject()
	{
	}



	void GameObject::tick(){
		if (script != nullptr) {
			script->run();
		}
		draw();
	}

	void GameObject::keyBoardEvent(Uint32 key){
		if (script != nullptr)
			script->keyBoardEvent(key);
	}

	void GameObject::test()
	{
		std::cout << "Test" << std::endl;
	}

/*
	void GameObject::move(int x, int y){

		rect.x += x;
		rect.y += y;
	}*/

	void GameObject::draw(){
		SDL_RenderCopy(renderer, texture, NULL, &rect);
	}


}