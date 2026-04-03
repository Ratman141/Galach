#include "include/lexer.h"

#include <stdexcept>

std::vector<std::string> Lexer::split(const std::string& source, const std::string& delim){
    std::vector<std::string> src;
    size_t start = 0, pos;
    if(delim == ""){
        for(char c : source){
            src.push_back(std::string(1, c));
        }
        return src;
    }
    while((pos = source.find(delim, start)) != std::string::npos){
        src.push_back(source.substr(start, pos - start));
        start = pos + delim.size();
    }
    src.push_back(source.substr(start));
    return src;
}

std::vector<Token> Lexer::tokenize(){
    auto vec = split(source, "");
    std::deque<std::string> src(vec.begin(), vec.end());
    std::vector<Token> tokens;
    Token token;
    int line = 1;
    // Make tokens until file ends
    while(!src.empty()){
        if(src[0] == " "){
            src.pop_front();
        }
        else if(src[0] == "\n"){
            line++;
            src.pop_front();
        }
        else if(src[0] == "G" || src[0] == "g"){
            token.line = line;
            token.type = TokenType::G_TOKEN;
            tokens.push_back(token);
            src.pop_front();
        }
        else if(src[0] == "L" || src[0] == "l"){
            token.line = line;
            token.type = TokenType::L_TOKEN;
            tokens.push_back(token);

            src.pop_front();
        }
        else if(src[0] == "A" || src[0] == "a"){
            token.line = line;
            token.type = TokenType::A_TOKEN;
            tokens.push_back(token);
            src.pop_front();
        }
        else if(src[0] == "C" || src[0] == "c"){
            token.line = line;
            token.type = TokenType::C_TOKEN;
            tokens.push_back(token);
            src.pop_front();
        }
        else if(src[0] == "H" || src[0] == "h"){
            token.line = line;
            token.type = TokenType::H_TOKEN;
            tokens.push_back(token);
            src.pop_front();
        }
        else 
            throw std::runtime_error("Unexpected token: " + src[0] + ", line: " + std::to_string(token.line));
    }
    token.type = TokenType::EOF_TOKEN;
    token.line = line;
    tokens.push_back(token);
    return tokens;
}