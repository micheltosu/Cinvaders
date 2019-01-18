#ifndef MEMBERFUNCTIONKEYBINDING_H
#define MEMBERFUNCTIONKEYBINDING_H
#include "KeybindingBase.h"

namespace ToMingine {
    template<typename T>
    class MemberFunctionKeybinding : public KeybindingBase {
    public:
        void execute(uint32_t);
        T* getObj() { return obj; }
        MemberFunctionKeybinding(T* inObj, void (T::*inFunk)(uint32_t));
        
    private:
        T* obj;
        void (T::*funk)(uint32_t);
    };
    
    template<typename T>
    MemberFunctionKeybinding<T>::MemberFunctionKeybinding(T* inObj, void (T::*inFunk)(uint32_t)) : obj(inObj), funk(inFunk) {}
    
    template<typename T>
    void MemberFunctionKeybinding<T>::execute(uint32_t key) {
        (obj->*funk)(key);
    }
    
}

#endif /* MEMBERFUNCTIONKEYBINDING_H */
