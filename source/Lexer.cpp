#include "../headers/Lexer.hpp"
#include <iostream>
#include <string>


Lexer::Lexer(string filename, string code){
    this->filename = filename;
    this->code = code;
	this->pos = new Position(0, 0, 0, filename);
};

Lexer::~Lexer(){}

void Lexer::tokenize(vector<Token*>* list, Errors::Error* err){
    vector<Token*>::iterator it;
    it = list->begin();
	current = code[0];
    while(current != NULL){
		cout << current << endl;
        if(WHITESPACES.find(current) != std::string::npos){
            nextChar();
        }
        else if(DIGITS.find(current) != std::string::npos){
			std::cout << "NUMBER" << endl;
            list->insert(it, parseNumber());
        }
        else{
			Token* tok;
            switch (current)
            {
                case '+':
					std::cout << "PLUS SIGN" << endl;
					list->insert(it, new Token(Enums::TokenType::TT_PLUS, pos->copy()));
                    break;
                case '-':
					std::cout << "MINUS SIGN" << endl;
					list->insert(it, new Token(Enums::TokenType::TT_MINUS, pos->copy()));
                    break;
                case '*':
					std::cout << "MULT SIGN" << endl;
					list->insert(it, new Token(Enums::TokenType::TT_MUL, pos->copy()));
                    break;
                case '/':
					std::cout << "DIV SIGN" << endl;
					list->insert(it, new Token(Enums::TokenType::TT_DIV, pos->copy()));
                    break;
                case '^':
					std::cout << "POW SIGN" << endl;
					tok = new Token(Enums::TokenType::TT_POW, pos->copy());
					std::cout << tok->getTypeName() << std::endl;
					list->insert(it, tok);
                    break;
                case '(':
					std::cout << "LPAREN SIGN" << endl;
					list->insert(it, new Token(Enums::TokenType::TT_RPAREN, pos->copy()));
                    break;
                case ')':
					std::cout << "RPAREN SIGN" << endl;
					list->insert(it, new Token(Enums::TokenType::TT_LPAREN, pos->copy()));
                    break;
                default:
					err = new Errors::Error();
                    break;
            }
			nextChar();
        }
    }
}

void Lexer::nextChar(){
    pos = pos->advance(current);
	printf("Idx: %d\n",pos->getIdx());
    current = (pos->getIdx() < code.length()) ? code[pos->getIdx()] : NULL;
}

Token* Lexer::parseNumber(){
    string numStr = "";
    int dotCount = 0;
    Position* start = pos->copy();
    string NUMBER = DIGITS + ".";
    while(current!=NULL && (NUMBER.find(current) != std::string::npos)){
		printf("RUNNING\n");
        if(current=='.'){
            if(dotCount==1)
                break;
            dotCount++;
        }
        numStr += current;
        nextChar();
    }
    if(dotCount==0)
        return new Token(Enums::TokenType::TT_INT, start, pos->copy(), std::stoi(numStr));
    return new Token(Enums::TokenType::TT_FLOAT, start, pos->copy(), std::stof(numStr));
}