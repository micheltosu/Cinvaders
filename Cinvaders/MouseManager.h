#ifndef MOUSEMANAGER_H
#define MOUSEMANAGER_H

#ifdef _WIN32
#include <SDL.h>
#elif defined (__APPLE__)
#include <SDL2/SDL.h>
#endif

#include <set>
#include "GameObject.h"

namespace ToMingine {
    class MouseManager {
    public:
        MouseManager() {};
        
        void addListener(GameObject*);
        void removeListener(GameObject*);
        void handleEvent(SDL_MouseButtonEvent&);
    private:
        void buttonPressed(SDL_MouseButtonEvent&);
        void buttonReleased(SDL_MouseButtonEvent&);
        
        std::set<GameObject*> listeners;
    };
}

#endif
