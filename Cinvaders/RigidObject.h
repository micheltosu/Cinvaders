#ifndef RIGID_OBJECT_H
#define RIGID_OBJECT_H
#include <string>
#include <iostream>
#include "GameObject.h"
//#include "GameEngine.h"


namespace ToMingine {
	class RigidObject :	public GameObject {
	public:
		RigidObject(std::string path);
		RigidObject(std::string path, int x, int y);
		~RigidObject();

		void move(int x, int y);

	private:
	};

}
#endif RIGID_OBJECT_H