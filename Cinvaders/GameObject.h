#include "RenderedObject.h"
#include <string>

namespace ToMingine {

class GameObject {
    public:
		GameObject(SDL_Renderer* renderer, std::string);
		~GameObject();
		void tick();
		int width, height;

    private:
		void draw();
		SDL_Rect rect;
		SDL_Renderer* renderer;
		SDL_Texture* texture;
		

	};
}