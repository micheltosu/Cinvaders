#include "Input.h"





Input::Input(unsigned int key, void(*fpek)()){
	pressedKey = key;
	myFunc = fpek;
}

Input::~Input()
{
}

Input * Input::createInstance(unsigned int key, void(*fpek)())
{
	return new Input(key, fpek);
}

void Input::doMe(unsigned int key){
	if(key == pressedKey)
	myFunc();
}
