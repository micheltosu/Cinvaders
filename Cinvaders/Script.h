#ifndef SCRIPT_H
#define SCRIPT_H

#ifdef _WIN32
#include <SDL.h>
#elif defined (__APPLE__)
#include <SDL2/SDL.h>
#endif

namespace ToMingine {
	class Script {
	public:
		virtual void keyBoardEvent(SDL_Event& keyEvent) {};
	};

}


#endif
