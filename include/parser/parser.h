#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include "../classes/node.h"
#include "../classes/token.h"
#include "../classes/tokenizer_pair.h"

Node* parse(std::vector<pair> tokens);

#endif  // PARSER_H