#ifndef KEYBINDINGBASE_H
#define KEYBINDINGBASE_H

class KeybindingBase {
public:
    virtual void execute() = 0;
    virtual ~KeybindingBase() {};
};
#endif
