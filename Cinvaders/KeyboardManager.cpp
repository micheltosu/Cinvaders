#include "KeyboardManager.h"
#include <iostream>
#include <list>
namespace ToMingine {
    void KeyboardManager::tick() {
        for (std::set<SDL_Keycode>::iterator it = pressedKey.begin(); it != pressedKey.end(); it++) {
            std::cout << "Key: " << *it << "pressed" << std::endl;
            // Sparar listan för att förkorta nedan uttryck
            
            if (bindings.find(*it) != bindings.end()) {
                std::cout << "Det finns " << bindings.find(*it)->second.size() << "bindings" << std::endl;
                std::list<void (*)()> bindingsList = bindings.find(*it)->second;
                
                for (std::list<void (*)()>::iterator bIt = bindingsList.begin() ; bIt != bindingsList.end(); bIt++) {
                    
                    std::cout << "Running binding: " << *bIt << " for " << *it << std::endl;
                    (*bIt)();
                }
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
        if(bindings.find(key) == bindings.end()) {
            auto newList = new std::list<void(*)()>();
            auto newPair = new std::pair<SDL_Keycode, std::list<void (*)()>>(key, *newList );
            
            
            bindings.insert(*newPair);
        }
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
