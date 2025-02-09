#include "object.hpp"
#include "int.hpp"

#include <string>

Int::Int(char *s) : Prim() { value = atoi(s); }
Int::Int(int n) : Prim() { value = n; }

Hex::Hex(char *s) : Int(std::stol(s, nullptr, 0x10)) {}
Oct::Oct(char *s) : Int(std::stol(s, nullptr, 0x08)) {}
Bin::Bin(char *s) : Int(std::stol(s, nullptr, 0x02)) {}
