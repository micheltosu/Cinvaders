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
#include "MemberFunctionKeybinding.h"
#include "GameObject.h"

namespace ToMingine {
class KeyboardManager {
public:
    KeyboardManager() {};
    void tick();
    void keyPressed(SDL_Keycode&, SDL_KeyboardEvent& kev);
    void keyReleased(SDL_Keycode&);
    void handleEvent(SDL_KeyboardEvent&);
    void handleEvent(SDL_TextInputEvent&);
    template<typename T>
    void addBinding(SDL_Keycode&, KeybindingBase*);
    void removeBinding(SDL_Keycode&, KeybindingBase*);
    void addListener(GameObject*);
    void removeListener(GameObject*);
    void removeBindingsFor(GameObject*);
    
private:
    std::map<SDL_Keycode, SDL_KeyboardEvent> pressedKey;
    std::set<GameObject *> listeners;
    std::map<SDL_Keycode, std::list<KeybindingBase*>> bindings;
    std::multimap<KeybindingBase*, GameObject*> objToBindMap;
    
    
};	


template<typename T>
void KeyboardManager::addBinding(SDL_Keycode& key, KeybindingBase* binding ) {
    if(bindings.find(key) == bindings.end()) {
        auto newList = new std::list<KeybindingBase* >();
        auto newPair = new std::pair<SDL_Keycode, std::list<KeybindingBase* >>(key, *newList );
        
        
        bindings.insert(*newPair);
        
        if(auto memBind = dynamic_cast<MemberFunctionKeybinding<T>*>(binding)) {
            GameObject* gobj = memBind->getObj()->getGameObject();
            
            objToBindMap.insert(std::pair<KeybindingBase*, GameObject*>(memBind, gobj));
        }
        
        
    }
    
    auto *vec = &(bindings.at(key));
    vec->push_back(binding);
}
}

#endif /* KeyboardManager_hpp */
