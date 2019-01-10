#include "RenderedObject.h"
#include "GameEngine.h"

namespace ToMingine {
    RenderedObject::RenderedObject() {
        renderer = GameEngine::getInstance().getRen();
    }
    
    RenderedObject::~RenderedObject() {
        
    }
}
