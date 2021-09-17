#ifndef Lexer_hpp
#define Lexer_hpp

#include <vector>

#include "Position.hpp"

#include "Token.hpp"

#include "Error.hpp"


class Lexer{
    public:
        Lexer(string filename, string code);
        ~Lexer();
        void tokenize(vector<Token*>* list = nullptr, Errors::Error* err = nullptr);
        
    private:
        //properties
        
        const string DIGITS = "0123456789";
        const string WHITESPACES = " \n\t";
        Position* pos;
        char current;
        string filename;
        string code;

        //methods
        void nextChar();
        Token* parseNumber();
};
#endif