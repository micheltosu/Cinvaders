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
    
    
    
    void KeyboardManager::addListener(GameObject *obj) {
        listeners.insert(obj);
    }
    
    void KeyboardManager::removeListener(GameObject* obj) {
        listeners.erase(obj);
    }
    
    void KeyboardManager::removeBindingsFor(GameObject * obj) {
        std::set<KeybindingBase*> toRemove;
        
        //För varje pair i objToBindMap
        for (auto oIt = objToBindMap.begin(); oIt != objToBindMap.end(); oIt++) {
            //Om ett par gäller för det objekt som ska få sina bindningar rensade.
            if (oIt->second == obj) {
                //För varje keycode som har bindings
                for (auto &kPair : bindings) {
                    //För varje binding i listan
                    typedef std::list<KeybindingBase*>::iterator kbItType;
                    std::vector<kbItType> removeIterators;
                    
                    for(auto kbIt = kPair.second.begin(); kbIt != kPair.second.end(); ++kbIt) {
                        if(*kbIt == oIt->first) {
                            toRemove.insert(oIt->first);
                            removeIterators.push_back(kbIt);
                        }
                    }
                    
                    for (kbItType it : removeIterators)
                        kPair.second.erase(it);
                    
                }
            }
            
            
            
        }
        
        for (KeybindingBase* kb : toRemove)
            objToBindMap.erase(kb);
        
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
