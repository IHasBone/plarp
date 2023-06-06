#include <cctype>
#include <stdexcept>
#include "../../include/lexer/lexer.h"


std::vector<pair> lex(const std::string& source) {
    std::vector<pair> tokens;

    int column = 0;
    int row = 1;

    std::string number = "";
    std::string identifier = "";

    bool functionDeclaration = false;

    for(char c : source) {
        column++;

        if (!std::isspace(c) && functionDeclaration) {
            if (c != ':') {
                throw std::runtime_error("Function declaration has to be proceeded by ':'. Invalid character '" + std::string{c} + "' at " + std::to_string(row) + ":" + std::to_string(column));
            } else {
                functionDeclaration = false;
            }
        }

        if (!std::isdigit(c) && number != "") {
            pair p;
            p.type = Integer;
            p.value = number;
            tokens.push_back(p);
            number = "";
        }

        if (!std::isalpha(c) && c != '_' && !std::isdigit(c) && identifier != "") {
            pair p;
            if (identifier == "true" || identifier == "false" || identifier == "null") {
                p.type = Boolean;
                p.value = identifier;
            } else if (identifier == "func") {
                p.type = Function;
                p.value = identifier;
                functionDeclaration = true;
            }
            
            tokens.push_back(p);
            identifier = "";
        }

        if (std::isalpha(c) || c == '_') {
            // identifier or keyword
            identifier.push_back(c);

        } else if (std::isdigit(c)) {
            // number
            if (identifier.empty()) {
                number.push_back(c);
            } else {
                identifier.push_back(c);
            }

        } else if (std::isspace(c)) {
            // space
            if (c == '\n') {
                column = 0;
                row++;
            }

        } else {
            std::string c_string{c};
            throw std::runtime_error("Invalid character '" + c_string + "' at " + std::to_string(row) + ":" + std::to_string(column));
        }
    }

    return tokens;
}