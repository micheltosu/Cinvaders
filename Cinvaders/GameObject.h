#include "RenderedObject.h"

namespace ToMingine {

class GameObject {
    public:
    GameObject();
    ~GameObject();
    void tick();
    void addRenderedObject(RenderedObject &obj);

    private:
    RenderedObject &ro;

};
}