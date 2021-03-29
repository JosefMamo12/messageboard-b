#include <cstring>
#include <iostream>
#include "Board.hpp"
#include "Direction.hpp"

using namespace std;

namespace ariel
{
    void Board::showHelper(unsigned int rows, unsigned int columns)
    {
        if (rows < this->_starting_row)
        {
            if (rows != 0)
            {
                this->_starting_row = rows - 1; // for the show function
            }

            else
            {
                this->_starting_row = rows;
            }
        }
        if (columns < this->_starting_column)
        {
            if (columns > 2)
            {
                this->_starting_column = columns - 2; // for the show function
            }
            else
            {
                this->_starting_column = columns;
            }
        }
    }
    void Board::resizeVector(unsigned int rows, unsigned int columns)
    {
        row() = max(row(), rows);
        column() = max(column(), columns);
        this->_board.resize(row());
        for (unsigned int i = 0; i < _board.size(); i++)
        {
            this->_board[i].resize(column() + 1, '_');
        }
    }
    //Board::post(1,4,Horizontal,"abc")
    /*
    _____
    __abc
    
    */
    void Board::post(unsigned int rows, unsigned int columns, Direction direct, const string &str)
    {
        if (str == empty_string)
        {
            return;
        }
        u_int index = 0;
        showHelper(rows, columns);
        if (direct == h)
        {
            if (rows >= row() || column() <= columns + str.length())
            {
                resizeVector(rows + 2, columns + str.length());
                while (index < str.length())
                {
                    this->_board[rows][columns++] = str[index++];
                }
            }
            else
            {
                while (index < str.length())
                {

                    this->_board[rows][columns++] = str[index++];
                }
            }
        }
        /*
        ===============================VERTICAL CASE==========================
        */
        else
        {
            if (rows + str.length() >= row() || columns >= column())
            {
                resizeVector(rows + str.length(), columns + 1);
                while (index < str.length())
                {
                    this->_board[rows++][columns] = str[index++];
                }
            }
            else
            {
                while (index < str.length())
                {
                    this->_board[rows++][columns] = str[index++];
                }
            }
        }
    }
    string Board::read(unsigned int rows, unsigned int columns, Direction direct, unsigned int string_length)
    {
        string ans = empty_string;
        int start = 0;

        if (columns >= column() || rows >= row())
        {
            for (size_t i = 0; i < string_length; i++)
            {
                ans += '_';
            }
        }
        else if (direct == h)
        {
            while (start < string_length)
            {
                if (columns <= column())
                {
                    ans += this->_board[rows][columns++];
                    start++;
                }
                else
                {
                    ans += '_';
                    start++;
                }
            }
        }
        else
        {
            while (start < string_length)
            {
                if (rows < row())
                {
                    ans += this->_board[rows++][columns];
                    start++;
                }
                else
                {
                    ans += '_';
                    start++;
                }
            }
        }
        return ans;
    }
    void Board::show()
    {
        if (row() == 0 && column() == 0)
        {
            cout << EMPTY_BOARD << endl;
        }
        for (unsigned int i = this->_starting_row; i < this->_board.size(); i++)
        {
            cout << i << ": ";
            for (unsigned int j = this->_starting_column; j < this->_board[i].size(); j++)
            {
                cout << (this->_board[i][j]);
                // cout << "ROW:" << i << " Column:" << j << " Suppose syntax: " << this->_board[i][j] << endl;
            }
            cout << endl;
        }
    }
    Board::~Board(){};
}
