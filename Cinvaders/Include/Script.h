#ifndef SCRIPT_H
#define SCRIPT_H

#ifdef _WIN32
#include <SDL.h>
#elif defined (__APPLE__)
#include <SDL2/SDL.h>
#endif

#include <map>
#include <iostream>

namespace ToMingine {
	class Script {
	public:
		virtual void run() = 0;
		virtual void keyBoardEvent(Uint32) {};
	};
}
#endif
