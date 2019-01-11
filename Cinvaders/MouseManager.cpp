#include "MouseManager.h"
#include <cstdio>
namespace ToMingine {
    MouseManager::MouseManager() {
        
    }
    
    void MouseManager::handleEvent(SDL_MouseButtonEvent& mev) {
        printf("MouseEvent: type: %u, button: %u, state: %u, clicks: %u, x,y: %d, %d\n", mev.type, mev.button, mev.state, mev.clicks, mev.x, mev.y);
        
        for (GameObject* listener : listeners)
            listener->mouseButtonEvent(mev);
        
        
    }
    
    void MouseManager::addListener(GameObject* go) {
        listeners.insert(go);
    }
    
    void MouseManager::removeListener(GameObject* go) {
        listeners.erase(go);
    }
    
    void MouseManager::buttonPressed(SDL_MouseButtonEvent& mev) {
        
    }
    
    void MouseManager::buttonReleased(SDL_MouseButtonEvent& mev) {
        
    }
}
