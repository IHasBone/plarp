#include <cctype>
#include <stdexcept>
#include "../../include/lexer/lexer.h"


std::vector<pair> lex(const std::string& source) {
    std::vector<pair> tokens;

    int column = 0;
    int row = 0;

    for(char c : source) {
        column++;
        row++;

        switch (c) {
            default:
                std::string c_string{c};
                throw std::runtime_error("Invalid character '" + c_string + "' at column " + std::to_string(column) + ", row " + std::to_string(row));
        }
    }

    return tokens;
}