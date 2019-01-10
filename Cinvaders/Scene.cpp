#include "Scene.h"
#include "GameEngine.h"
#include <iostream>
#include <typeinfo>
#include "InputField.h" // temp
namespace ToMingine {

Scene::Scene(){}

Scene::Scene(std::string bgPath){
    setBackground(bgPath);
    keyMan = GameEngine::getInstance().keyboardManager();
}


Scene::~Scene(){}
void Scene::setBackground(std::string filename) {
    background = IMG_LoadTexture(GameEngine::getInstance().getRen(), filename.c_str());
    if (background == nullptr) {
        std::cout << "Error: cannot load image: " << filename << std::endl;
        std::cout << SDL_GetError() << std::endl;
        exit(-1);
    }
}
void Scene::addObject(GameObject * go){
    gameObjects.push_back(go);
}
void Scene::removeObject(GameObject* go){
	toRemove.push_back(go);
	
}

bool Scene::run(){
    
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            GameEngine::getInstance().Quit();
            break;
        case SDL_KEYDOWN:
			keyMan->keyPressed(event.key.keysym.sym);
            break;
        case SDL_KEYUP:

            keyMan->keyReleased(event.key.keysym.sym);
            break;
        } // switch end
        
    } // event loop
    keyMan->tick();

    SDL_RenderClear(GameEngine::getInstance().getRen());
    SDL_RenderCopy(GameEngine::getInstance().getRen(), background, NULL, NULL);
    for (GameObject* go : gameObjects) {
        go->tick();
    }
    
    if (toRemove.size() > 0) {
        for (auto go : toRemove) {
            std::list<GameObject*>::iterator i = gameObjects.begin();
            while (i != gameObjects.end()) {
                if (*i == go) {
                    auto* i2 = *i;
                    gameObjects.erase(i++);
                    delete i2;
                    break;
                }
            i++;
            }
        }
        toRemove.clear();
    }
    return false;
}
}
