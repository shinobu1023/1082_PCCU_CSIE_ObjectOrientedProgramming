/*==========================================

第一題-matrix_min

==========================================*/

#include <iostream>
#include <vector> // 將會使用到 vector
using namespace std;

// 找出 vector 中最小值
int min(vector<vector<int> > matrix)
{
    // 先將第一個值設為預設最小值
    int minimum = matrix[0][0];
    // 用迴圈依序造訪 vector 中每一個值比較大小
    for (int i = 0; i < matrix.size(); i++)
        for (int j = 0; j < matrix[i].size(); j++)
            minimum = (matrix[i][j] < minimum) ? matrix[i][j] : minimum;
    // 回傳最小值
    return minimum;
}
// 主程式
int main()
{
    // 宣告一個變數為欲輸入的值
    int input;
    // 宣告一個二維 vector
    vector<vector<int> > matrix(4, vector<int>(3));
    // 用迴圈輸入12個值並依序存入 vector
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cin >> input;
            matrix[i][j] = input;
        }
    }
    // 將 vector 透過函式找出最小值並輸出
    cout << "min: " << min(matrix) << endl;

    return 0;
}