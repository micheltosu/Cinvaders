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
    enum Direction {HORIZ, VERT};
    class RigidObject :    public GameObject {
    public:
        static RigidObject* create(Sprite* spr, Type t, int x, int y);
        ~RigidObject();
        
        void move(int x, int y);
		void collision(Type t);

		GameObject* requestMove(int& x, int& y) {
			Direction dir = HORIZ;
			return requestMove(x, y, dir);
		}

	protected:
        RigidObject(Sprite* spr, Type t);
        RigidObject(Sprite* spr, Type t, int x, int y);
        
		GameObject* requestMove(int&, int&, Direction&);
    private:
		int GetAlphaXY(int x, int y);
		bool pixelDetection(RigidObject* ro, int x, int y, Direction&);
        const int SPEED = 1;
        
    };

}
#endif
