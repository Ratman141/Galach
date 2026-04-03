#pragma once

#include "lexer.h"
#include <vector>

class Interpreter{
    private:
        std::vector<Token> tokens;
        unsigned char memory[30000] = {0};
        size_t pointer = 0;
    public:
        void run();
        Interpreter(std::vector<Token> tokens) : tokens(tokens){};
};