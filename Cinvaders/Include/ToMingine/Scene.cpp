#include "Scene.h"
#include "GameEngine.h"
#include <iostream>

namespace ToMingine {

Scene::Scene(){}

Scene::Scene(std::string bgPath){
    setBackground(bgPath);
    keyMan = GameEngine::getInstance().keyboardManager();
    mouseMan = GameEngine::getInstance().mouseManager();
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
    
void Scene::draw() {
    SDL_RenderClear(GameEngine::getInstance().getRen());
    SDL_RenderCopy(GameEngine::getInstance().getRen(), background, NULL, NULL);
    for (GameObject* go : gameObjects) {
        go->draw();
    }
}

bool Scene::run(){
    
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            GameEngine::getInstance().Quit();
            break;
        case SDL_KEYDOWN:
        case SDL_KEYUP:
            keyMan->handleEvent(event.key);
            break;
        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEBUTTONUP:
            mouseMan->handleEvent(event.button);
            break;
        case SDL_TEXTINPUT:
            keyMan->handleEvent(event.text);
            break;
        } // switch end
        
    } // event loop
    
    keyMan->tick();

   
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
