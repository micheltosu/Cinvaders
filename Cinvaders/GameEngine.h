#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H


#ifdef _WIN32

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#elif defined (__APPLE__)
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <SDL2_ttf/SDL_ttf.h>
#endif

#include "GameObject.h"
#include "RigidObject.h"
#include <iostream>
#include <string>
#include <vector>

namespace ToMingine {

	class GameEngine {

        public:
			~GameEngine();
        
			void run();
			void add(GameObject*);
			void remove(GameObject*);
			void updateWindow();
			void setBackground(std::string filename);
			SDL_Renderer* getRen() { return renderer; }
			std::vector<GameObject*>* getGameObjects();

		static GameEngine& getInstance(){
			static GameEngine instance;
			return instance;
		}

		private:
			GameEngine();
			const int FPS = 30;
			const int tickInterval = 1000 / FPS;
			SDL_Window *window;
			SDL_Renderer *renderer;
			SDL_Texture *background;
			std::vector<GameObject*> gameObjects;

			int window_width = 1280;
			int window_height = 720;
			bool start = true;
	        
			GameEngine(const GameEngine& other)	= delete;
			const GameEngine& operator=(const GameEngine& other) = delete;

    };
}
#endif // !GAME_ENGINE_H