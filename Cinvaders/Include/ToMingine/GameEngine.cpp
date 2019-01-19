#include "GameEngine.h"

namespace ToMingine {


	void GameEngine::run() {
		
		while (!quit) {
            Uint32 sdlTicks = SDL_GetTicks();
			Uint32 nextTick = sdlTicks + tickInterval;
            
			if (currentScene->run())
				nextScene();
            if(sdlTicks - lastDraw > (1000/FPS) ) {
                currentScene->draw();
                SDL_RenderPresent(renderer);
                lastDraw = sdlTicks;
            }
            
			//FPS
			int delay = nextTick - SDL_GetTicks();
			if (delay > 0)
				SDL_Delay(delay);
		} // yttre while
	}
    
    void GameEngine::destroyGameOject(GameObject * go) {
        for (Scene *s : scenes) {
            s->removeObject(go);
        }
        
        keyMan->removeListener(go);
        keyMan->removeBindingsFor(go);
        mouseMan->removeListener(go);
        
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
        
        // Stop text input on start.
        SDL_StopTextInput();

		keyMan = new KeyboardManager();
        mouseMan = new MouseManager();
	}

	GameEngine::~GameEngine() {
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		TTF_Quit();
		SDL_Quit();
	}

}
