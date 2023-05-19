#include <fstream>
#include <sstream>

#include "../include/lexer/lexer.h"
#include "../include/parser/parser.h"
#include "../include/classes/tokenizer_pair.h"
#include "../include/interpreter/interpreter.h"


int main(int argc, char** argv) {
    std::string f = argv[1];
    std::ifstream file(f);
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string source = buffer.str();
    
    std::vector<pair> tokens = lex(source);
    Node* ast = parse(tokens);
    interpret(ast);

    return 0;
}