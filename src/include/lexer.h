#pragma once

#include <string>
#include <vector>
#include <deque>

enum class TokenType{
    // literals
    G_TOKEN,        // Go up
    L_TOKEN,        // Go down
    A_TOKEN,        // Add 1
    C_TOKEN,        // Sub 1
    H_TOKEN,        // Print
    EOF_TOKEN
};

struct Token{
    TokenType type;
    int line;
};

class Lexer{
    private:
        std::string source;
    public:
        std::vector<std::string> split(const std::string& source, const std::string& delim);        // Makes source code into vector
        std::vector<Token> tokenize();
        Lexer(std::string src) : source(src){};
};
