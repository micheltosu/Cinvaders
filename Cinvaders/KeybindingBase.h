#ifndef KEYBINDINGBASE_H
#define KEYBINDINGBASE_H
#include <stdint.h>

class KeybindingBase {
public:
    virtual void execute(uint32_t) = 0;
    virtual ~KeybindingBase() {};
};
#endif
