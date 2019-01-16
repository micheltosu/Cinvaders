#include "FunctionKeybinding.h"
#include <iostream>
#include <stdint.h>

namespace ToMingine {
    FunctionKeybinding::FunctionKeybinding(void (*inFun)(uint32_t)) : funk(inFun) { }
    
    void FunctionKeybinding::execute(uint32_t key) {
        funk(key);
    }
}

