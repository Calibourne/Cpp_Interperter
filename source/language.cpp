#include <iostream>
#include <vector>
#include "../headers/Lexer.hpp"
using std::vector;
namespace Language{

	void run(string filename, string code){
		Lexer lexer = *new Lexer(filename, code);
		vector<Token*>* list = {};
		Errors::Error* err = nullptr;
		lexer.tokenize(list, err);
		/*bool e = err != nullptr;
		std::cout << e;
		if(err!=nullptr){
			vector<Token> l = *list;
			for(int i = 0; i < list->size();i++){
				std::cout << l[i] << std::endl;
			}
		}*/
	}
}