#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Direction.hpp"

using namespace std;
const string empty_string = "";

namespace ariel
{
    int static counter = 0;
    const Direction v = Direction::Vertical;
    const Direction h = Direction::Horizontal;
    class Board
    {

        vector<vector<char>> _board;
        unsigned int _column, _row, _starting_row, _starting_column;

    public:
        Board(unsigned int rows = 0, unsigned int columns = 0, unsigned int starting_row = INT32_MAX, unsigned int starting_column = INT32_MAX) : _column(columns),
                                                                                                                                                  _row(rows),
                                                                                                                                                  _starting_row(starting_row),
                                                                                                                                                  _starting_column(starting_column)
        {
        }
        void post(unsigned int rows, unsigned int columns, Direction direct, const string &str);
        string read(unsigned int rows, unsigned int columns, Direction direct, unsigned int string_length);
        unsigned int &column() { return _column; } // getter and setters
        unsigned int &row() { return _row; }       // getter and setter
        void resizeVector(unsigned int, unsigned int);
        void show();
        void showHelper(unsigned int, unsigned int);

        ~Board();
    };
}
