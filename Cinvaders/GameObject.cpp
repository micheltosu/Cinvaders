#include "GameObject.h"

namespace ToMingine {
	GameObject::GameObject(SDL_Renderer* renderer, std::string path) {

		this->renderer = renderer;
		SDL_Surface* surface = IMG_Load(path.c_str());
		texture = SDL_CreateTextureFromSurface(renderer, surface);
		rect = { 0, 0, surface->w, surface->h };
		SDL_FreeSurface(surface);
	}

	void GameObject::tick(){
		draw();
	}

	void GameObject::draw(){
		SDL_RenderCopy(renderer, texture, NULL, &rect);
	}
}