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

const string POST_ROW_MESSAGE = "Please choose row which you would like to post: ";
const string POST_COLU_MESSAGE = "Please choose column  which you would like to post: ";
const string READ_ROW_MESSAGE = "Please choose row which you would like to read: ";
const string READ_COLU_MESSAGE = "Please choose column which you would like to read: ";
const string READ_STRING_LENGTH = "Please enter the length of the string you would like to see: ";
const string ERROR_MESSAGE = "Pressed worng key returning to the menu";

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
    cout << "===============================================================================" << endl;
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
        cout << "6. To Exit press: E" << endl;

        op = cin.get();
        switch (op)
        {
        case 'A':
            cout << POST_ROW_MESSAGE << endl;
            if (!(cin >> row))
            {
                cout << ERROR_MESSAGE << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                break;
            }
            cout << POST_COLU_MESSAGE << endl;
            if (!(cin >> column))
            {
                cout << ERROR_MESSAGE << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                break;
            }
            cin.ignore();
            cout << "Type your post here: " << endl;
            getline(cin, toPost);
            board.post(row, column, h, toPost);
            break;
        case 'B':
            cout << POST_ROW_MESSAGE << endl;
            if (!(cin >> row))
            {
                cout << ERROR_MESSAGE << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                break;
            }
            cout << POST_COLU_MESSAGE << endl;
            if (!(cin >> column))
            {
                cout << ERROR_MESSAGE << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                break;
            }
            cin.ignore();
            cout << "Type your post here: " << endl;
            getline(cin, toPost);
            board.post(row, column, v, toPost);
            break;
        case 'C':
            cout << READ_ROW_MESSAGE << endl;
            if (!(cin >> row))
            {
                cout << ERROR_MESSAGE << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                break;
            }
            cout << READ_COLU_MESSAGE << endl;
            if (!(cin >> column))
            {
                cout << ERROR_MESSAGE << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                break;
            }
            cout << READ_STRING_LENGTH << endl;
            cin >> string_length;
            cout << board.read(row, column, h, string_length) << endl;
            break;
        case 'D':
            cout << READ_ROW_MESSAGE << endl;
            if (!(cin >> row))
            {
                cout << ERROR_MESSAGE << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                break;
            }
            cout << READ_COLU_MESSAGE << endl;
            if (!(cin >> column))
            {
                cout << ERROR_MESSAGE << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                break;
            }
            cout << READ_STRING_LENGTH << endl;
            cin >> string_length;
            cout << board.read(row, column, v, string_length) << endl;
            break;
        case 'S':
            cin.clear();
            cin.ignore(10000, '\n');
            board.show();
            break;
        case 'E':
            flag = false;
            break;
        default:
            cout << ERROR_MESSAGE << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            break;
        }
    } while (flag);
    cout << "==============================================================================" << endl;
    cout << "==============================================================================" << endl;
    cout << "==================================GOODBYE=====================================" << endl;
    cout << "==============================================================================" << endl;
    cout << "==============================================================================" << endl;
}
