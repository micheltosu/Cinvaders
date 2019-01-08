#ifndef FUNCTIONKEYBINDING_H
#define FUNCTIONKEYBINDING_H

#include "KeybindingBase.h"

namespace ToMingine {
    
    class FunctionKeybinding : public KeybindingBase {
    public:
        FunctionKeybinding(void (*fun)(uint32_t));
        void execute(uint32_t);
    private:
        void (*funk)(uint32_t);
        
    };   
}


#endif 
