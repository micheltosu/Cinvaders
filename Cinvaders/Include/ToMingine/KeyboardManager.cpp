#include "KeyboardManager.h"
#include "MemberFunctionKeybinding.h"
#include "PlayerScript.h"
#include <iostream>
#include <list>
namespace ToMingine {
    void KeyboardManager::tick() {
        // for all pressed keys.
        for (std::set<SDL_Keycode>::iterator keyIt = pressedKey.begin(); keyIt != pressedKey.end(); keyIt++) {

            //If bindings for the key exists
            if (bindings.find(*keyIt) != bindings.end()) {
                std::list<KeybindingBase* > bindingsList = bindings.find(*keyIt)->second;
                
                // For all keybindings
                for (std::list<KeybindingBase* >::iterator bIt = bindingsList.begin() ; bIt != bindingsList.end(); bIt++) {
                    
                    (*bIt)->execute(*keyIt);
                } // End all keybindings
                
                
            } // End if binding for key exists
            
            
            
        } // end for pressed keys
        
    }
    
    void KeyboardManager::handleEvent(SDL_KeyboardEvent& kev) {
        switch (kev.type) {
            case SDL_KEYDOWN:
                keyPressed(kev.keysym.sym);
                break;
            case SDL_KEYUP:
                keyReleased(kev.keysym.sym);
                break;
        }
        // For all listeners
        for (GameObject* oPoint : listeners) {
            oPoint->keyBoardEvent(kev);
        } // End for all listeners
    
    }
    
    void KeyboardManager::handleEvent(SDL_TextInputEvent& tev) {
        for (GameObject* oPoint : listeners) {
            oPoint->textInputEvent(tev);
        } // End for all listeners
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
    }
    
    void KeyboardManager::addListener(GameObject *obj) {
        listeners.insert(obj);
    }
    
    void KeyboardManager::removeListener(GameObject* obj) {
        listeners.erase(obj);
    }
    
    void KeyboardManager::removeBindingsFor(GameObject * obj) {
        for (auto &kPair : bindings) {
            for( auto it = kPair.second.begin(); it != kPair.second.end(); it++) {
                if (MemberFunctionKeybinding<PlayerScript>* memberFBind = dynamic_cast<MemberFunctionKeybinding<PlayerScript>*>(*it)) {
                    if (memberFBind->isBindingForObj(dynamic_cast<PlayerScript*>(obj->script))) {
                        kPair.second.erase(it);
                        
                    }
                }
            }
        }
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
