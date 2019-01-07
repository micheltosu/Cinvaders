#ifndef KeyboardManager_h
#define KeyboardManager_h

#ifdef _WIN32

#include <SDL.h>


#elif defined (__APPLE__)

#include <SDL2/SDL.h>
#endif

#include <set>
#include <map>
#include <list>
#include <stdio.h>

namespace ToMingine {
class KeyboardManager {
public:
    KeyboardManager() {};
    void tick();
    void keyPressed(SDL_Keycode&);
    void keyReleased(SDL_Keycode&);
    void addBinding(SDL_Keycode&, void(*)());
    void removeBinding(SDL_Keycode&, void(*)());
    
private:
    std::set<SDL_Keycode> pressedKey;
    std::map<SDL_Keycode, std::list<void (*)()>> bindings;
    
    
};
}


#endif /* KeyboardManager_hpp */
