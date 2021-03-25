#include <string>
#include <iostream>
#include "Direction.hpp"
using namespace std;

namespace ariel{
    class Board{

    public:

    void post(unsigned int row, unsigned int col, ariel::Direction dir, string message);
    string read(unsigned int row, unsigned int col, ariel::Direction dir, unsigned int length);
    void show();
    };
}
