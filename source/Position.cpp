#include "../headers/Position.hpp"

Position::Position(int idx, int line, int column, string filename){
    this->idx = idx;
    this->line = line;
    this->column = column;
    this->filename = filename;
}

Position::~Position(){}

int Position::getIdx(){
    return this->idx;
}

Position* Position::advance(char current){
    idx++;
    column++;
    if(current == '\n'){
        column = 0;
        line++;
    }
    return this;
}

Position* Position::copy(){
    return new Position(this->idx, this->line, this->column, this->filename);
}