#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <string>
#include <iostream>


using namespace std;
int main(int argc, char** argv) {
	int window_width = 1280;
	int window_height = 720;


	//Inititalizers
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	SDL_Window* window = SDL_CreateWindow("Titel", 100, 100, window_width, window_height, 0);
	SDL_Renderer* render = SDL_CreateRenderer(window, -1, 0);






	//Destroyers
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(window);
	TTF_Quit();
	SDL_Quit();
	return 0;
}