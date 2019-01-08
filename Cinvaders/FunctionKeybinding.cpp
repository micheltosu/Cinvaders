#include "FunctionKeybinding.h"
#include <iostream>

namespace ToMingine {
    FunctionKeybinding::FunctionKeybinding(void (*inFun)()) : funk(inFun) { }
    
    void FunctionKeybinding::execute() {
        std::cout << "Execute Function Keybinding" << std::endl;
        funk();
    }
}

