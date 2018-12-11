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

	GameObject player1;
	Sprite p1sprite;
	Player p1char; 
	player1.addRenderedObject(p1sprite);
	player1.addGameChar(p1char);



	
	gm.run();

	return 0;
}