#include <iostream>
#include <string>
#include <vector>
//#include "language.cpp"
#include "../headers/Lexer.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
//using Language::run;
void run(string fn, string code);
int main(int argc, char const *argv[])
{
    string code;

	vector<int> vec = {};
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	for(int i = 0; i < vec.size(); i++)
		cout << vec[i] << endl;

    do{
        cout << "Rouge > ";
        getline(cin, code);
		run("stdin", code);
    }while(code != "");
    return 0;
}

void run(string filename, string code) {
	Lexer lexer = *new Lexer(filename, code);
	vector<Token*>* list = new vector<Token*>();
	Errors::Error* err = nullptr;
	lexer.tokenize(list, err);
	string str = (err == nullptr) ? "TRUE" : "FALSE";
	cout << str << endl;
	if (err == nullptr) {
		if (list->size() > 0)
			printf("token list size: %d\n", list->size());
		for (int i = 0; i < list->size(); i++) {
			Token* t = list->at(i);
			printf("%s\n", t->getType());
		}
	}
}