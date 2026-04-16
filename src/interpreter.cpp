#include "include/interpreter.h"
#include <iostream>

void Interpreter::run(){
    size_t i = 0;
    while(i < tokens.size()){
        Token token = tokens[i];
        if(token.type == TokenType::G_TOKEN){
            if(pointer == 29999) pointer = 0;
            else pointer++;
        }
        else if(token.type == TokenType::L_TOKEN){
            if(pointer == 0) pointer = 29999;
            else pointer--;
        }
        else if(token.type == TokenType::A_TOKEN){
            memory[pointer]++;
        }
        else if(token.type == TokenType::C_TOKEN){
            memory[pointer]--;
        }
        else if(token.type == TokenType::H_TOKEN){
            std::cout<<memory[pointer];
        }
        else if(token.type == TokenType::L_PAREN){
            loop_data = pointer;
            loop_index = i;
        }
        else if(token.type == TokenType::R_PAREN){
            if(memory[loop_data] != 0){
                i = loop_index;
                continue;
            }
        }
        i++;
    }
}