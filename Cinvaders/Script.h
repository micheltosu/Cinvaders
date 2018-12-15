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
		virtual void run() {};
		virtual void keyBoardEvent(SDL_Event& keyEvent) {};

		template <typename RET, typename ARG>
		void addInput(Uint32 key, RET(*fpek)(ARG)) {
			input[key] = fpek;
		}

		template <typename RET>
		void addInput(Uint32 key, RET(*fpek)()) {
			input[key] = fpek;
		}

		void runInput(SDL_Event& key) {
			input.at(key.key.keysym.sym)();
		}

		void runInput(Uint32 key) {
			input.at(key)();
		}

	private:
		std::map<Uint32, void (*)()> input;
	};

}



#endif
