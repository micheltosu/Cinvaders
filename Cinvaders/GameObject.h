#include "RenderedObject.h"
#include <string>

namespace ToMingine {

class GameObject {
    public:
		GameObject(SDL_Renderer* renderer, std::string);
		GameObject();
		~GameObject();
		void tick();
		SDL_Renderer* renderer;

		SDL_Texture* texture;

    private:
		void draw();

};
}