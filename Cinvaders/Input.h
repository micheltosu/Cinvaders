#ifndef INPUT_H
#define INPUT_H

class Input
{
public:
	Input(unsigned int, void (*fpek)());
	~Input();
	Input* createInstance(unsigned int, void(*fpek)());
	void doMe(unsigned int);

private:
	unsigned int pressedKey;
	void (*myFunc)();


};

#endif

/*template<typename T>
inline Input::Input(unsigned int key, T* func) { this.key = key; myFunc = func; }

template<typename T>
inline Input* Input::createInstance(unsigned int key, T* func){
	return new Input<T>(key, func);
}*/

