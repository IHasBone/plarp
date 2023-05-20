#include <cctype>
#include <stdexcept>
#include "../../include/lexer/lexer.h"


std::vector<pair> lex(const std::string& source) {
    std::vector<pair> tokens;

    int column = 0;
    int row = 1;

    std::string t = "";

    for(char c : source) {
        column++;

        if (!std::isdigit(c) && t != "") {
            pair p;
            p.type = Literal;
            p.value = t;
            tokens.push_back(p);
            t = "";
        }

        if (std::isalpha(c) || c == '_') {
            // identifier or keyword
                
        } else if (std::isdigit(c)) {
            // number
            t.push_back(c);

        } else if (std::isspace(c)) {
            // space
            if (c == '\n') {
                column = 0;
                row++;
            }

        } else {
            std::string c_string{c};
            throw std::runtime_error("Invalid character '" + c_string + "' at column " + std::to_string(column) + ", row " + std::to_string(row));
        }
    }

    return tokens;
}