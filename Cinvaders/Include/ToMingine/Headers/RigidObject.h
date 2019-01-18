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
<<<<<<< HEAD:Cinvaders/Include/ToMingine/Headers/RigidObject.h
    
    class RigidObject : public GameObject {
=======
    enum Direction {HORIZ, VERT};
    class RigidObject :    public GameObject {
>>>>>>> origin/Pixel_Collision:Cinvaders/RigidObject.h
    public:
		RigidObject(std::string path, Type t);
        RigidObject(Sprite* spr, Type t);
		RigidObject(std::string path, Type t, int x, int y);
        RigidObject(Sprite* spr, Type t, int x, int y);
        ~RigidObject();
        
        void move(int x, int y);
		void collision(Type t);
<<<<<<< HEAD:Cinvaders/Include/ToMingine/Headers/RigidObject.h
        int GetAlphaXY(int x, int y);
		bool pixelDetection(RigidObject*);
        GameObject* requestMove(int, int);

=======


		GameObject* requestMove(int& x, int& y) {
			Direction dir = HORIZ;
			return requestMove(x, y, dir);
		}


        void move(int x, int y);

	protected:
		GameObject* requestMove(int&, int&, Direction&);
>>>>>>> origin/Pixel_Collision:Cinvaders/RigidObject.h
    private:
		int GetAlphaXY(int x, int y);
		bool pixelDetection(RigidObject* ro, int x, int y, Direction&);
        const int SPEED = 1;
        
    };

}
#endif