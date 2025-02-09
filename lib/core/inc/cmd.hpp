#pragma once

#include "object.hpp"

/// @defgroup cmd cmd
/// @ingroup vm
/// @brief @ref VM command
/// @{

/// @brief command opcode for @ref bc generation
typedef u8 Op;

/// @brief @ref VM command
class Cmd : public Object {
   public:
    void exec();  ///< execute command over global @ref vm
   private:
    static const Op op;  ///< command opcode for @ref bc generation
};

/// @defgroup fctl flow control
/// @{

/// `0x00` `( -- )` empty command: do nothing
class Nop : public Cmd {
    static const Op op = 0x00;
};

/// `0xFF` `( -- )` stop system
class Halt : public Cmd {
    static const Op op = 0xFF;
};

/// @}

/// @defgroup stack stack ops
/// @{

/// `0x10` `( n -- n n )`
class Dup : public Cmd {
    static const Op op = 0x10;
};

/// `0x11` `( n -- )`
class Drop : public Cmd {
    static const Op op = 0x11;
};

/// `0x12` `( n1 n2 -- n2 n1 )`
class Swap : public Cmd {
    static const Op op = 0x12;
};

/// `0x13` `( n1 n2 -- n1 n2 n1 )`
class Over : public Cmd {
    static const Op op = 0x13;
};

/// `0x14` `( n1 n2 n3 -- n2 n3 n1 )`
class Rot : public Cmd {
    static const Op op = 0x14;
};

/// `0x15` `( n1 n2 n3 -- n3 n1 n2 )`
class mRot : public Cmd {
    static const Op op = 0x15;
};

/// `0x16` `( ... ni ... n0 i -- ... ni ... n0 ni )` pick element by index
class Pick : public Cmd {
    static const Op op = 0x16;
};

/// `0x17` `( ni ... -- ni ... i )` current stack depth
class Depth : public Cmd {
    static const Op op = 0x17;
};

/// @}

/// @}
