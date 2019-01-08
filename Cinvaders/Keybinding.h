//
//  KeyBinding.hpp
//  CINVADERS
//
//  Created by Michel Tosu on 2019-01-08.
//  Copyright © 2019 Michel Tosu. All rights reserved.
//

#ifndef KEYBINDING_H
#define KEYBINDING_H

namespace ToMingine {
    
    template<typename T>
    class Keybinding {
    public:
        Keybinding(T* obj, void (T::*fun)());
        void execute();
    private:
        const T* obj;
        const void (T::*funk)();
        
    };
    
    template<typename T>
    Keybinding<T>::Keybinding(T* inObj, void (T::*inFun)()) {
        obj = inObj;
        funk = inFun;
    }
    
    template<typename T>
    void Keybinding<T>::execute() {
        obj->*funk();
    }
}


#endif /* KeyBinding_hpp */
