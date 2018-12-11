#include <string>
#include <iostream>
#include "GameEngine.h"

using namespace std;
int main(int argc, char** argv) {
	int window_width = 1280;
	int window_height = 720;

	ToMingine::GameEngine gm = ToMingine::GameEngine::getInstance();

	SDL_Delay(15000);

	return 0;
}