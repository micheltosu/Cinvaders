#ifndef SCRIPT_H
#define SCRIPT_H

#ifdef _WIN32
#include <SDL.h>
#elif defined (__APPLE__)
#include <SDL2/SDL.h>
#endif

#include "GameEngine.h"

namespace ToMingine {
	class Script {
	public:
        virtual ~Script() {}
		virtual void run() = 0;
		virtual void keyBoardEvent(const SDL_KeyboardEvent&) {};
        virtual void textInputEvent(const SDL_TextInputEvent&) {};
		virtual void collision(Type t) {};
        virtual GameObject* getGameObject() = 0;
        
    protected:
        Script() {}
    private:
        Script(const Script&) = delete;
        const Script& operator=(const Script&) = delete;
	};
}
#endif
