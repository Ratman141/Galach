#include "include/lexer.h"
#include "include/interpreter.h"
#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {

    // Checks for correct number of arguments
    if(argc < 1){
        std::cerr<<"Error: Not enough arguments provided."<<std::endl;
        return 1;
    }
    if(argc > 2){
        std::cerr<<"Error: Too many arguments provided."<<std::endl;
        return 1;
    }

    if(argc < 2){
        std::cerr<<"Error: No file provided to run."<<std::endl;
        return 1;
    }

    std::string fileName = argv[1];


    if(fileName.size() < 3){
        std::cerr<<"Error: Invalid file name."<<std::endl;
        return 1;
    }
        
    std::string fileExtension = fileName.substr(fileName.size() - 2);

    if(fileExtension != ".g"){
        std::cerr<<"Error: Invalid file type. Expected .g file."<<std::endl;
        return 1;
    }
    // Opens file
    std::ifstream file;
    file.open(fileName);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file.\n";
        return 1;
    }

    // Loads file to string
    std::string source, line;
    while(std::getline(file, line)){
        source += line + "\n";
    }

    // Interpreter

    try{
        Lexer lexer(source);
        std::vector<Token> tokens = lexer.tokenize();
        Interpreter interpreter(tokens);
        interpreter.run();
    }
    catch(const std::runtime_error& e){
        std::cerr<<e.what()<<std::endl;
    }

    file.close();


    return 0;
}
