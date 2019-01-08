#ifndef FUNCTIONKEYBINDING_H
#define FUNCTIONKEYBINDING_H

#include "KeybindingBase.h"

namespace ToMingine {
    
    class FunctionKeybinding : public KeybindingBase {
    public:
        FunctionKeybinding(void (*fun)());
        void execute();
    private:
        void (*funk)();
        
    };   
}


#endif 
