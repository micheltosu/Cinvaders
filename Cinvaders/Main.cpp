#include <string>
#include <iostream>
#include "GameEngine.h"
#include "PlayerScript.h"

using namespace std;
using namespace ToMingine;


void myFunc() {
	std::cout << "Jag pekar!!!" << std::endl;
}

int main(int argc, char** argv) {
	int window_width = 1280;
	int window_height = 720;

	ToMingine::GameEngine gm = ToMingine::GameEngine::getInstance();
	gm.setBackground("Resources/Image/background.png");

	GameObject* go = new GameObject("Resources/Image/ship.png");
	PlayerScript* s = new PlayerScript(go);
	go->addScript(s);
	gm.add(go);



	void(*fpek)() = myFunc;
	Input n = Input(1, fpek);
	go->addInput(n);

	gm.run();

	return 0;
}