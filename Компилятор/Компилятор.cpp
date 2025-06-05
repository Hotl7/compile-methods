
#include <iostream>

#include "Lexer.h"
#include "Parser.h"

int main()
{
    Lexer lex("real n;");
    
    
    Parser parser(lex.get_tokens());

}


