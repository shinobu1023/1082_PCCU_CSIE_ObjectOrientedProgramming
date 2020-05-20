/*==========================================

第三題-vector with template

==========================================*/

/* 本題重點： 一維 vector 傳遞、vector 找最大值、vector 排序、vector 使用 template  */

#include <iostream>
#include <iomanip>   // 將會使用到 setprecision
#include <vector>    // 將會使用到 vector
#include <algorithm> // 將會使用到 sort
using namespace std;

// 找出 vector 中最大值
template <typename T>
T max(vector<T> matrix)
{
    // 先將第一個值設為預設最大值
    T maximum = matrix[0];
    // 用迴圈依序造訪 vector 中每一個值比較大小
    for (int i = 0; i < matrix.size(); i++)
        maximum = (matrix[i] > maximum) ? matrix[i] : maximum;
    // 回傳最大值
    return maximum;
}
// 主程式
int main()
{
    // 宣告一個整數 vector
    vector<int> integerMatrix(12);
    // 宣告一個浮點數二維 vector
    vector<double> decimalMatrix(12);
    // 用迴圈輸入12個整數值並依序存入整數 vector
    for (int i = 0; i < integerMatrix.size(); i++)
        cin >> integerMatrix[i];
    // 用迴圈輸入12個浮點數值並依序存入浮點數 vector
    for (int i = 0; i < decimalMatrix.size(); i++)
        cin >> decimalMatrix[i];
    // 排序後印出
    sort(integerMatrix.begin(), integerMatrix.end());
    // integerMatrix = insertionSortReturnVector(integerMatrix);
    // insertionSortByReference(integerMatrix);
    cout << "Integer vector sort:" << endl;
    for (int i = 0; i < integerMatrix.size(); i++)
        cout << integerMatrix[i] << " ";
    // 找最大值
    cout << "\nInteger vector maximum value: " << max(integerMatrix) << endl;
    // 排序後印出
    sort(decimalMatrix.begin(), decimalMatrix.end());
    // decimalMatrix = insertionSortReturnVector(decimalMatrix);
    // insertionSortByReference(decimalMatrix);
    cout << "\nDecimal vector sort:" << endl;
    for (int i = 0; i < decimalMatrix.size(); i++)
        cout << setprecision(1) << fixed << decimalMatrix[i] << " ";
    // 找最大值
    cout << "\nDecimal vector maximum value: " << max(decimalMatrix) << endl;

    return 0;
}

/*================ insertionSort 原始正常版本 ================*/
void insertionSort(int list[], int listSize)
{
    for (int i = 1; i < listSize; i++)
    {
        int currentElement = list[i];
        int k;
        for (k = i - 1; k >= 0 && list[k] > currentElement; k--)
        {
            list[k + 1] = list[k];
        }
        list[k + 1] = currentElement;
    }
}
/*==========================================================*/

/*============ insertionSort 示範 1 (回傳 vector) ============*/
template <typename T>
vector<T> insertionSortReturnVector(vector<T> list)
{
    for (int i = 1; i < list.size(); i++)
    {
        T currentElement = list[i];
        int k;
        for (k = i - 1; k >= 0 && list[k] > currentElement; k--)
        {
            list[k + 1] = list[k];
        }
        list[k + 1] = currentElement;
    }

    return list;
}
/*==========================================================*/

/*=============== insertionSort 示範 2 (傳遞位址) ============*/
template <typename T>
void insertionSortByReference(vector<T> &list)
{
    for (int i = 1; i < list.size(); i++)
    {
        T currentElement = list[i];
        int k;
        for (k = i - 1; k >= 0 && list[k] > currentElement; k--)
        {
            list[k + 1] = list[k];
        }
        list[k + 1] = currentElement;
    }
}
/*==========================================================*/