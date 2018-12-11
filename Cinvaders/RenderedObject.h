#ifdef _WIN32

#include <SDL.h>
#include <SDL_image.h>

#elif defined (__APPLE__)
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#endif
namespace ToMingine {


class RenderedObject {
    public:
    virtual void draw();
    RenderedObject(SDL_Renderer *);

    private:
    SDL_Renderer *rend;
};
}