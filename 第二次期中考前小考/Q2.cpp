/*==========================================

第二題-template reverse

==========================================*/

#include <iostream>
using namespace std;

// 反轉函式
template <typename T>
void reverse(const T list[], T newList[], int size)
{
    for (int i = 0, j = size - 1; i < size; i++, j--)
    {
        newList[j] = list[i];
    }
}
// 輸出陣列函式
template <typename T>
void printArray(const T list[], int size)
{
    for (int i = 0; i < size; i++)
        cout << list[i] << " ";
}
// 主程式
int main()
{
    // 宣告一個常數為陣列大小
    const int SIZE = 6;
    // 根據題目宣告一個字元陣列
    char list[SIZE] = {'a', 'b', 'c', 'd', 'e', 'f'};
    // 宣告一個反轉後要存入的字元陣列
    char newList[SIZE];
    // 透過函式反轉
    reverse(list, newList, SIZE);
    // 輸出尚未反轉的原始陣列
    cout << "The original array: ";
    printArray(list, SIZE);
    cout << endl;
    // 輸出反轉後的陣列
    cout << "The reversed array: ";
    printArray(newList, SIZE);
    cout << endl;
    // 根據題目宣告一個浮點數陣列
    double list2[SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
    // 宣告一個反轉後要存入的浮點數陣列
    double newList2[SIZE];
    // 透過函式反轉
    reverse(list2, newList2, SIZE);
    // 輸出尚未反轉的原始陣列
    cout << "The original array: ";
    printArray(list2, SIZE);
    cout << endl;
    // 輸出反轉後的陣列
    cout << "The reversed array: ";
    printArray(newList2, SIZE);
    cout << endl;

    return 0;
}