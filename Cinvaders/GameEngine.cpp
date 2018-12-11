#include "GameEngine.h"
#include <iostream>

namespace ToMingine {

    void GameEngine::updateWindow() {
        SDL_RenderClear(renderer);
        //updateGameObjects();
        SDL_Rect rekt = {0, 0, 1280, 720};
        SDL_RenderCopy(renderer, background, NULL, &rekt);
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

    void GameEngine::setBackground(std::string filename) {
        background = IMG_LoadTexture(renderer, filename.c_str());
        if (background == nullptr) {
            std::cout << "Error: cannot load image: " << filename << std::endl;
            std::cout << SDL_GetError() << std::endl;
            exit(-1);
        }


    }

    GameEngine::GameEngine() {
        SDL_Init(SDL_INIT_EVERYTHING);
        TTF_Init();

        SDL_Window* window = SDL_CreateWindow("Titel", 100, 100, window_width, window_height, 0);
        if (window  == nullptr) {
            std::cout << "Error: cannot load window: " << std::endl;
            std::cout << SDL_GetError() << std::endl;
            exit(-1);
        }
        SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer  == nullptr) {
            std::cout << "Error: cannot load renderer: " << std::endl;
            std::cout << SDL_GetError() << std::endl;
            exit(-1);
        }

        background = IMG_LoadTexture(renderer, "/Users/michel/git/Cinvaders/Resources/Image/background.png");
        if (background == nullptr) {
            std::cout << "Error: cannot load image: " << std::endl;
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

    GameEngine gm;
}