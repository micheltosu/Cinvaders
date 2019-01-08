#include "KeyboardManager.h"
#include <iostream>
#include <list>
namespace ToMingine {
    void KeyboardManager::tick() {
        for (std::set<SDL_Keycode>::iterator it = pressedKey.begin(); it != pressedKey.end(); it++) {
            // Sparar listan för att förkorta nedan uttryck
            std::cout << "Run" << std::endl;
            if (bindings.find(*it) != bindings.end()) {
                std::list<KeybindingBase* > bindingsList = bindings.find(*it)->second;
                
                for (std::list<KeybindingBase* >::iterator bIt = bindingsList.begin() ; bIt != bindingsList.end(); bIt++) {
                    
                    (*bIt)->execute();
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
    
    void KeyboardManager::addBinding(SDL_Keycode& key, KeybindingBase* binding ) {
        if(bindings.find(key) == bindings.end()) {
            auto newList = new std::list<KeybindingBase* >();
            auto newPair = new std::pair<SDL_Keycode, std::list<KeybindingBase* >>(key, *newList );
            
            
            bindings.insert(*newPair);
        }
        
        auto *vec = &(bindings.at(key));
        vec->push_back(binding);
        
        //std::cout << "Bindings for: " << key << " is now: " << bindings.at(key).size() << std::endl;
    }
    
    void KeyboardManager::removeBinding(SDL_Keycode& key, KeybindingBase* binding) {
        auto lis = bindings.at(key);
        for (KeybindingBase* bind: lis ) {
            if (bind == binding) {
                lis.remove(bind);
            }
        }
        
    }
}
