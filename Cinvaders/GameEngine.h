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

namespace ToMingine {


    class GameEngine {
        public:
        static GameEngine& getInstance();
        ~GameEngine();

        private:
        GameEngine();
        
        SDL_Window *window;
        SDL_Renderer *renderer;

        int window_width = 1280;
        int window_height = 720;
        
    };
}