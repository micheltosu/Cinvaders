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
#include "KeybindingBase.h"
#include "GameObject.h"

namespace ToMingine {
class KeyboardManager {
public:
    KeyboardManager() {};
    void tick();
    void keyPressed(SDL_Keycode&);
    void keyReleased(SDL_Keycode&);
    void addBinding(SDL_Keycode&, KeybindingBase*);
    void removeBinding(SDL_Keycode&, KeybindingBase*);
    void addListener(GameObject*);
    void removeListener(GameObject*);
    
private:
    std::set<SDL_Keycode> pressedKey;
    std::set<GameObject *> listeners;
    std::map<SDL_Keycode, std::list<KeybindingBase*>> bindings;
    
    
};	
}


#endif /* KeyboardManager_hpp */
