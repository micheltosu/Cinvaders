#ifndef RIGID_OBJECT_H
#define RIGID_OBJECT_H

#ifdef __APPLE__
#include <SDL2/SDL.h>
#elif defined _WIN32
#include <SDL.h>
#endif


#include <string>
#include <iostream>
#include "GameObject.h"

namespace ToMingine {
    
    class RigidObject : public GameObject {
    public:
		RigidObject(std::string path, Type t);
        RigidObject(Sprite* spr, Type t);
		RigidObject(std::string path, Type t, int x, int y);
        RigidObject(Sprite* spr, Type t, int x, int y);
        ~RigidObject();
        
        void move(int x, int y);
		void collision(Type t);
        int GetAlphaXY(int x, int y);
		bool pixelDetection(RigidObject*);
        GameObject* requestMove(int, int);

    private:
        const int SPEED = 1;
        
    };

}
#endif
