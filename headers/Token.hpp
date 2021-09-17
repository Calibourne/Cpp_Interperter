#ifndef Token_hpp
#define Token_hpp

#include "Position.hpp"
#include <any>
#include <iostream>
using namespace std;
namespace Enums{
    enum TokenType {
        TT_INT,
        TT_FLOAT,
        TT_PLUS,
        TT_MINUS,
        TT_MUL,
        TT_DIV,
        TT_POW,
        TT_LPAREN,
        TT_RPAREN,
    };
}

class Token{
    public:
		Token(Enums::TokenType type, Position* start = nullptr, Position* end = nullptr, any value = NULL);
		~Token(){};
		any getValue() {
			return value;
		};
		Enums::TokenType getType() {
			return type;
		};
		string getTypeName();
		Position* getStart() {
			return start;
		};
		Position* getEnd() {
			return end;
		};
    private:
        Enums::TokenType type;
        any value;
        Position* start;
        Position* end;

};
#endif