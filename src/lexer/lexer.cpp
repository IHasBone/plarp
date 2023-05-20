#include <cctype>
#include <stdexcept>
#include "../../include/lexer/lexer.h"


std::vector<pair> lex(const std::string& source) {
    std::vector<pair> tokens;

    int column = 0;
    int row = 1;

    std::string d = "";
    std::string t = "";

    for(char c : source) {
        column++;

        if (!std::isdigit(c) && d != "") {
            pair p;
            p.type = Integer;
            p.value = d;
            tokens.push_back(p);
            d = "";
        }

        if ((!std::isalpha(c) || c == '_') && t != "") {
            pair p;
            if (t == "true" || t == "false" || t == "null") {
                p.type = Boolean;
                p.value = t;
            }

            tokens.push_back(p);
            t = "";
        }

        if (std::isalpha(c) || c == '_') {
            // identifier or keyword
            t.push_back(c);

        } else if (std::isdigit(c)) {
            // number
            d.push_back(c);

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