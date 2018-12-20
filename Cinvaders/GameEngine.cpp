#include "GameEngine.h"

namespace ToMingine {


    void GameEngine::updateWindow() {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, background, NULL, NULL);
        for (GameObject* go : gameObjects) {
            go->tick();
        }
        SDL_RenderPresent(renderer);
    }

    void GameEngine::run() {
        bool quit = false;
        Uint32 key = 0;
        int keysPressed = 0;

        while (!quit) {
            Uint32 nextTick = SDL_GetTicks() + tickInterval;
            SDL_Event event;
            while( SDL_PollEvent(&event)) {
                switch (event.type) {
                    case SDL_QUIT:
                        quit = true;
                        break;
                    case SDL_KEYDOWN:
                        if (key != event.key.keysym.sym) {
                            key = event.key.keysym.sym;
                            keysPressed++;
                        }
                        
                        keyMan->keyPressed(event.key.keysym.sym);
                        break;
                    case SDL_KEYUP:
                        keysPressed--;
                        if(keysPressed == 0)
                            key = 0;
                        
                        keyMan->keyReleased(event.key.keysym.sym);
                        break;
                } // switch end
            } // event loop
			
            keyMan->tick();
            for (GameObject* go : gameObjects) {
                go->keyBoardEvent(key);
            }
            updateWindow();
            int delay = nextTick - SDL_GetTicks();
            if (delay > 0)
                SDL_Delay(delay);
        } // yttre while
    }

    void GameEngine::add(GameObject* go){
        gameObjects.push_back(go);
    }

	void GameEngine::remove(GameObject * o){
		for (unsigned int i = 0; i < gameObjects.size(); i++) {
			if(gameObjects[i] == o)
				gameObjects.erase(gameObjects.begin()+i);
		}
	}

    void GameEngine::setBackground(std::string filename) {
        background = IMG_LoadTexture(renderer, filename.c_str());
        if (background == nullptr) {
            std::cout << "Error: cannot load image: " << filename << std::endl;
            std::cout << SDL_GetError() << std::endl;
            exit(-1);
        }


    }

    std::vector<GameObject*>* GameEngine::getGameObjects(){
        return &gameObjects;
    }

    GameEngine::GameEngine() {
        if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
            std::cout << SDL_GetError() << std::endl;
            exit(-1);
        }
        
        TTF_Init();

        window = SDL_CreateWindow("ToMingine", 100, 100, window_width, window_height, 0);
        if (window  == nullptr) {
            std::cout << "Error: cannot load window: " << std::endl;
            std::cout << SDL_GetError() << std::endl;
            exit(-1);
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer  == nullptr) {
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
