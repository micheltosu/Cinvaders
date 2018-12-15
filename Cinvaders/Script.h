#ifndef SCRIPT_H
#define SCRIPT_H

#ifdef _WIN32
#include <SDL.h>
#elif defined (__APPLE__)
#include <SDL2/SDL.h>
#endif

#include <map>

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
		input.find(key.key.keysym.sym);
	}

	private:
		std::map<Uint32, void (*)()> input;
	};

}



#endif
