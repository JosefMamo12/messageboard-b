#include <cmath>
#include <array>
#include "Board.hpp"
// #include "doctest.h"
using namespace ariel;

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    u_int row, column, string_length = 0;
    bool flag = true;
    char op;
    string toPost;
    Board board;

    cout << "===============================================================================" << endl;
    cout << "===============================================================================" << endl;
    cout << "Hello this is menu for the Message Board please choose one of the options below" << endl;
    cout << "===============================================================================" << endl;
    cout << "===============================================================================a" << endl;
    cout << endl;

    do
    {
        cout << "1. To post horizontal message please press: A"
             << endl;
        cout << "2. To post vertical message please press: B"
             << endl;
        cout << "3. To read horizontal message please press: C"
             << endl;
        cout << "4. To read vertical message please press: D"
             << endl;
        cout << "5. Would you like to see the message board please press: S"
             << endl;
        cout << "6. Press any other key to EXIT" << endl;
        cin >> op;
        switch (op)
        {
        case 'A':
            cout << "Please choose row which you would like to post: " << endl;
            cin >> row;
            cout << "Please choose column which you would like to post: " << endl;
            cin >> column;
            cin.ignore();
            cout << "Type your post here: " << endl;
            getline(cin, toPost);
            board.post(row, column, h, toPost);
            break;
        case 'B':
            cout << "Please choose row which you would like to post: " << endl;
            cin >> row;
            cout << "Please choose column which you would like to post: " << endl;
            cin >> column;
            cin.ignore();
            cout << "Type your post here: " << endl;
            getline(cin, toPost);
            board.post(row, column, v, toPost);
            break;
        case 'C':
            cout << "Please choose row which you would like to start read: " << endl;
            cin >> row;
            cout << "Please choose column which you would like to start read: " << endl;
            cin >> column;
            cout << "Please enter the length of the string:" << endl;
            cin >> string_length;
            cout << board.read(row, column, h, string_length) << endl;
            break;
        case 'D':
            cout << "Please choose row which you would like to start read: " << endl;
            cin >> row;
            cout << "Please choose column which you would like to start read: " << endl;
            cin >> column;
            cout << "Please enter the length of the string:" << endl;
            cin >> string_length;
            cout << board.read(row, column, v, string_length) << endl;
            break;
        case 'S':
            board.show();
            break;
        default:
            flag = false;
            break;
        }
    } while (flag);
    cout << "==============================================================================" << endl;
    cout << "==============================================================================" << endl;
    cout << "==================================GOODBYE=====================================" << endl;
    cout << "==============================================================================" << endl;
    cout << "==============================================================================" << endl;
}
