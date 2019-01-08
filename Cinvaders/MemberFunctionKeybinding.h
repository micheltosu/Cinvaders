#ifndef MEMBERFUNCTIONKEYBINDING_H
#define MEMBERFUNCTIONKEYBINDING_H
#include "KeybindingBase.h"

namespace ToMingine {
    template<typename T>
    class MemberFunctionKeybinding : public KeybindingBase {
    public:
        void execute();
        MemberFunctionKeybinding(T* inObj, void (T::*inFunk)());
        
    private:
        T* obj;
        void (T::*funk)();
    };
    
    template<typename T>
    MemberFunctionKeybinding<T>::MemberFunctionKeybinding(T* inObj, void (T::*inFunk)()) : obj(inObj), funk(inFunk) {}
    
    template<typename T>
    void MemberFunctionKeybinding<T>::execute() {
        (obj->*funk)();
    }
    
}

#endif /* MEMBERFUNCTIONKEYBINDING_H */
