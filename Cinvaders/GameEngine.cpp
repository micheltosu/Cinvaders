#include "GameEngine.h"

namespace ToMingine {

    GameEngine &GameEngine::getInstance() {
        GameEngine instance;

        return instance;
    }


    GameEngine::GameEngine() {
        SDL_Init(SDL_INIT_EVERYTHING);
        TTF_Init();

        SDL_Window* window = SDL_CreateWindow("Titel", 100, 100, window_width, window_height, 0);
        SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

        SDL_Delay(15000);
      
    }

    GameEngine::~GameEngine() {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
    }
}