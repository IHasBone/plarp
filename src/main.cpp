#include "../include/lexer/lexer.h"
#include "../include/parser/parser.h"
#include "../include/classes/tokenizer_pair.h"
#include "../include/interpreter/interpreter.h"


int main(int argc, char** argv) {
    std::string file = argv[1];
    
    std::vector<pair> tokens = lex(file);
    Node* ast = parse(tokens);
    interpret(ast);

    return 0;
}