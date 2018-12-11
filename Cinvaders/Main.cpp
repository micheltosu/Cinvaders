#include <string>
#include <iostream>
#include "GameEngine.h"

using namespace std;
using namespace ToMingine;
int main(int argc, char** argv) {
	int window_width = 1280;
	int window_height = 720;

	ToMingine::GameEngine gm = ToMingine::GameEngine::getInstance();
	gm.setBackground("Resources/Image/background.png");
	
	gm.run();

	return 0;
}