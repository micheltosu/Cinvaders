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

        while (!quit) {
            SDL_Event event;

            while( SDL_PollEvent(&event)) {
                switch (event.type) {
                    case SDL_QUIT:
                        quit = true;
                        break;
                } // switch end
            } // event loop
			

            updateWindow();
            
        } // yttre while
    }

	void GameEngine::add(std::string path){
		gameObjects.push_back(new GameObject(renderer,path));
	}

    void GameEngine::setBackground(std::string filename) {
        background = IMG_LoadTexture(renderer, filename.c_str());
        if (background == nullptr) {
            std::cout << "Error: cannot load image: " << filename << std::endl;
            std::cout << SDL_GetError() << std::endl;
            exit(-1);
        }


    }

    GameEngine &GameEngine::getInstance() {
        static GameEngine gm; 

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