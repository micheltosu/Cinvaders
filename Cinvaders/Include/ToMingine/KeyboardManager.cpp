#include "KeyboardManager.h"
#include "MemberFunctionKeybinding.h"
#include "PlayerScript.h"
#include <iostream>
#include <list>
namespace ToMingine {
    void KeyboardManager::tick() {
        // for all pressed keys.
        for (std::map<SDL_Keycode, SDL_KeyboardEvent>::iterator keyIt = pressedKey.begin(); keyIt != pressedKey.end(); keyIt++) {

            //If bindings for the key exists
            if (bindings.find(keyIt->first) != bindings.end()) {
                std::list<KeybindingBase* > bindingsList = bindings.find(keyIt->first)->second;
                
                // For all keybindings
                for (std::list<KeybindingBase* >::iterator bIt = bindingsList.begin() ; bIt != bindingsList.end(); bIt++) {
                    
                    (*bIt)->execute(keyIt->first);
                } // End all keybindings
                
                
            } // End if binding for key exists
            
            // For all listeners
            for (GameObject* oPoint : listeners) {
                oPoint->keyBoardEvent(pressedKey[keyIt->first]);
            } // End for all listeners
            
        } // end for pressed keys
        
    }
    
    void KeyboardManager::handleEvent(SDL_KeyboardEvent& kev) {
        switch (kev.type) {
            case SDL_KEYDOWN:
                keyPressed(kev.keysym.sym, kev);
                break;
            case SDL_KEYUP:
                keyReleased(kev.keysym.sym);
                break;
        }
    }
    
    void KeyboardManager::handleEvent(SDL_TextInputEvent& tev) {
        for (GameObject* oPoint : listeners) {
            oPoint->textInputEvent(tev);
        } // End for all listeners
    }
    
    void KeyboardManager::keyPressed(SDL_Keycode& key, SDL_KeyboardEvent &kev) {
        pressedKey[key] = kev;
        
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
                    
                    // Remove the found keybindings
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
