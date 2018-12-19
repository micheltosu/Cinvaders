#include "KeyboardManager.h"
#include <iostream>

namespace ToMingine {
    void KeyboardManager::tick() {
        if ( pressedKey.empty()) { std::cout << "no pressed key set exists" << std::endl;}
        for (std::set<SDL_Keycode>::iterator it = pressedKey.begin(); it != pressedKey.end(); it++) {
            // Sparar listan för att förkorta nedan uttryck
            std::list<void (*)()> bindingsList = bindings.find(*it)->second;
            for (std::list<void (*)()>::iterator bIt = bindingsList.begin() ; bIt != bindingsList.end(); bIt++) {
                (*bIt)();
            }
        }
    }
    
    void KeyboardManager::keyPressed(SDL_Keycode& key) {
        pressedKey.insert(key);
    }
    
    void KeyboardManager::keyReleased(SDL_Keycode& key) {
        pressedKey.erase(key);
    }
    
    void KeyboardManager::addBinding(SDL_Keycode& key, void (*funk)() ) {
        auto vec = bindings.at(key);
        vec.push_back(funk);
    }
    
    void KeyboardManager::removeBinding(SDL_Keycode& key, void (*funk)()) {
        auto lis = bindings.at(key);
        for (void (*f)() : lis ) {
            if (f == funk) {
                lis.remove(f);
            }
        }
        
    }
}
