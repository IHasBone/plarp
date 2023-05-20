#ifndef TOKEN_H
#define TOKEN_H

enum token {
    Keyword,
    Variable,
    Function,
    Operator,
    String,
    Integer,
    Boolean,
    Punctuation,
    EndExpr,
};

#endif  // TOKEN_H