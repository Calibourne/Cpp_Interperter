#include "../headers/Token.hpp"

Token::Token(Enums::TokenType type, Position* start, Position* end, any value) {
			this->type = type;
			this->start = start;
			this->end = end;
			this->value = value;
};

string Token::getTypeName(){
	switch (type) {
	case Enums::TokenType::TT_INT:
		return "int";
	case Enums::TokenType::TT_FLOAT:
		return "float";
	case Enums::TokenType::TT_PLUS:
		return "plus";
	case Enums::TokenType::TT_MINUS:
		return "minus";
	case Enums::TokenType::TT_MUL:
		return "mul";
	case Enums::TokenType::TT_DIV:
		return "div";
	case Enums::TokenType::TT_POW:
		return "pow";
	case Enums::TokenType::TT_LPAREN:
		return "lparen"; 
	case Enums::TokenType::TT_RPAREN:
		return "rparen";
	}
};