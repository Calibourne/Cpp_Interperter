#ifndef Position_hpp
#define Position_hpp
#include <iostream>
using std::string;
class Position{
    private:
        int idx;
        int line;
        int column;
        string filename;

    public:
        Position(int idx, int line, int column, string filename);
        ~Position();
        int getIdx();
        Position* advance(char current);
        Position* copy();
};
#endif