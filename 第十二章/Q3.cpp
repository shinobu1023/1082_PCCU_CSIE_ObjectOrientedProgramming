/*==========================================

第三題-GuessBirthDay

==========================================*/

#include <iostream>
#include <iomanip>
#include <vector> // 將會使用到 vector
using namespace std;

int main()
{
    int day = 0;
    char answer;

    // 宣告一個 5*4*4 的三維 vector
    vector<vector<vector<int>>> date(5);
    for (int i = 0; i < date.size(); i++)
    {
        date[i] = vector<vector<int>>(4);
        for (int j = 0; j < date[i].size(); j++)
        {
            date[i][j] = vector<int>(4);
        }
    }

    int dates[5][4][4] = {
        {{1, 3, 5, 7},
         {9, 11, 13, 15},
         {17, 19, 21, 23},
         {25, 27, 29, 31}},
        {{2, 3, 6, 7},
         {10, 11, 14, 15},
         {18, 19, 22, 23},
         {26, 27, 30, 31}},
        {{4, 5, 6, 7},
         {12, 13, 14, 15},
         {20, 21, 22, 23},
         {28, 29, 30, 31}},
        {{8, 9, 10, 11},
         {12, 13, 14, 15},
         {24, 25, 26, 27},
         {28, 29, 30, 31}},
        {{16, 17, 18, 19},
         {20, 21, 22, 23},
         {24, 25, 26, 27},
         {28, 29, 30, 31}}};

    // 將陣列中的值放至三維 vector 中
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                date[i][j][k] = dates[i][j][k];
            }
        }
    }

    for (int i = 0; i < date.size(); i++)
    {
        cout << "Is your birthday in Set" << (i + 1) << "?" << endl;
        for (int j = 0; j < date[i].size(); j++)
        {
            for (int k = 0; k < date[i][j].size(); k++)
                cout << setw(3) << date[i][j][k] << " ";
            cout << endl;
        }
        cout << "\nEnter N for No and Y for Yes: ";
        cin >> answer;
        if (answer == 'Y')
            day += dates[i][0][0];
    }

    cout << "Your birthday is " << day << endl;

    return 0;
}