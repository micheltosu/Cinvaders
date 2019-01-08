#include "GameEngine.h"

namespace ToMingine {


	void GameEngine::run() {
		
		while (!quit) {
			Uint32 nextTick = SDL_GetTicks() + tickInterval;
			keyMan->tick();
			if (currentScene->run())
				nextScene();
			SDL_RenderPresent(renderer);
			//FPS
			int delay = nextTick - SDL_GetTicks();
			if (delay > 0)
				SDL_Delay(delay);
		} // yttre while
	}

	void GameEngine::addScene(Scene * s){
		if (scenes.empty())
			currentScene = s;
		scenes.push_back(s);
	}

	void GameEngine::nextScene(){
		std::list<Scene*>::iterator it;
		for (it = scenes.begin(); it != scenes.end(); it++) {
			if (*it == currentScene) {
				if (++it == scenes.end()) {
					currentScene = *scenes.begin();
				}
				else {
					currentScene = *it;
				}
				break;
			}
		}
	}


	GameEngine::GameEngine() {
		if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
			std::cout << SDL_GetError() << std::endl;
			exit(-1);
		}

		TTF_Init();

		window = SDL_CreateWindow("ToMingine", 100, 100, window_width, window_height, 0);
		if (window == nullptr) {
			std::cout << "Error: cannot load window: " << std::endl;
			std::cout << SDL_GetError() << std::endl;
			exit(-1);
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer == nullptr) {
			std::cout << "Error: cannot load renderer: " << std::endl;
			std::cout << SDL_GetError() << std::endl;
			exit(-1);
		}

		keyMan = new KeyboardManager();
	}

	GameEngine::~GameEngine() {
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		TTF_Quit();
		SDL_Quit();
	}

}