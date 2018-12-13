#include "GameObject.h"

namespace ToMingine {
	GameObject::GameObject(SDL_Renderer* renderer, std::string path) {
		texture = IMG_LoadTexture(renderer, path.c_str());
		this->renderer = renderer;
	}


	void GameObject::tick(){
		draw();
	}

	void GameObject::draw(){
		SDL_RenderCopy(renderer, texture, NULL, NULL);
	}
}