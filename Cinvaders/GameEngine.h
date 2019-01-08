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
#include "KeyboardManager.h"
#include "Scene.h"
#include <iostream>
#include <string>
#include <list>

namespace ToMingine {


	class GameEngine {

	public:
		~GameEngine();


		void run();
		void addScene(Scene* s);
		void setCurrentScene(Scene* s) { currentScene = s; }
		Scene* getCurrentScene() { return currentScene; }
		SDL_Renderer* getRen() { return renderer; }
		void nextScene();


		void Quit() { quit = true; }

		static GameEngine& getInstance() {
			static GameEngine instance;
			return instance;
		}
		
		int window_width = 1280;
		int window_height = 720;

		KeyboardManager *keyboardManager() { return keyMan; }
	private:
		GameEngine();
		const int FPS = 40;
		const int tickInterval = 1000 / FPS;
		SDL_Window *window;
		SDL_Renderer *renderer;
		
		KeyboardManager *keyMan;
		std::list<Scene*> scenes;
		
		Scene* currentScene;

		bool quit = false;
		GameEngine(const GameEngine& other) = delete;
		const GameEngine& operator=(const GameEngine& other) = delete;


	};
}
#endif // !GAME_ENGINE_H