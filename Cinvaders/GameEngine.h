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
#include <iostream>
#include <string>
#include <vector>

namespace ToMingine {


    class GameEngine {
        public:
        ~GameEngine();
        static GameEngine &getInstance();
        
        void run();
		void add(std::string);
		void remover(GameObject*);
        void updateWindow();
        void setBackground(std::string filename);
        private:
        GameEngine();
        
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Texture *background;
		std::vector<GameObject*> gameObjects;

        int window_width = 1280;
        int window_height = 720;
        
    };

    //extern GameEngine gm;
    
}