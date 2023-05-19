#ifndef LEXER_H
#define LEXER_H

#include <vector>
#include <string>
#include "../classes/token.h"
#include "../classes/tokenizer_pair.h"

std::vector<pair> lex(const std::string& source);

#endif  // LEXER_H