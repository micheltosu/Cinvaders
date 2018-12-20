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
						break;
					case SDL_KEYUP:
						keysPressed--;
						if(keysPressed == 0)
							key = 0;
						break;
                } // switch end
            } // event loop
			
			std::cout << gameObjects.size() << std::endl;

			for (GameObject* go : gameObjects) {
				go->keyBoardEvent(key);
			}
			updateWindow();
        } // yttre while
    }

	void GameEngine::add(GameObject* go){
		gameObjects.push_back(go);
	}

    void GameEngine::setBackground(std::string filename) {
        background = IMG_LoadTexture(renderer, filename.c_str());
        if (background == nullptr) {
            std::cout << "Error: cannot load image: " << filename << std::endl;
            std::cout << SDL_GetError() << std::endl;
            exit(-1);
        }


    }

	bool GameEngine::requestMove(GameObject* movingObject){
		std::cout << "REQUEST MADE!" << std::endl;
		SDL_Rect* movingRect = movingObject->getRect();
		SDL_Rect* otherRect;
		std::cout << gameObjects.size() << std::endl;
		for (GameObject* go : gameObjects){
			std::cout << "OBJECT EXISTS!" << std::endl;
			otherRect = go->getRect();
			if (go != movingObject) {
				std::cout << "MORE OBJECTS EXISTS!" << std::endl;
				if (
					otherRect->x + otherRect->w <= movingRect->x &&
					movingRect->x + movingRect->w <= otherRect->x &&
					otherRect->y + otherRect->h <= movingRect->y &&
					movingRect->x + otherRect->h <= otherRect->y
					) {
					std::cout << "COLLISION" << std::endl;
					return false;
				}
			}
		}
		return true;
	}

	

    GameEngine *GameEngine::getInstance() {
		if (!nullptr)
			gm = new GameEngine();
        return gm;
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
    }

    GameEngine::~GameEngine() {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
    }
        
}