#include "GameObject.h"
#include "GameEngine.h"

namespace ToMingine {
	GameObject::GameObject(std::string path) {

		renderer = GameEngine::getInstance().getRen();
		SDL_Surface* surface = IMG_Load(path.c_str());
		texture = SDL_CreateTextureFromSurface(renderer, surface);
		rect = { 0, 0, surface->w, surface->h };
		SDL_FreeSurface(surface);
	}



	void GameObject::tick(SDL_Event& event){
		if (script) {
			script->keyBoardEvent(event);
		}
		draw();
	}

	void GameObject::draw(){
		SDL_RenderCopy(renderer, texture, NULL, &rect);
	}
}