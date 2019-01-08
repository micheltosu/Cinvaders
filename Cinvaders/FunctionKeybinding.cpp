#include "FunctionKeybinding.h"
#include <iostream>
#include <stdint.h>

namespace ToMingine {
    FunctionKeybinding::FunctionKeybinding(void (*inFun)(uint32_t)) : funk(inFun) { }
    
    void FunctionKeybinding::execute(uint32_t key) {
        std::cout << "Execute Function Keybinding" << std::endl;
        funk(key);
    }
}

