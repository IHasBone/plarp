#ifndef TOKENIZER_PAIR_H
#define TOKENIZER_PAIR_H

#include <string>
#include "token.h"

struct pair {
    token type;
    std::string value;
};

#endif  // TOKENIZER_PAIR_H