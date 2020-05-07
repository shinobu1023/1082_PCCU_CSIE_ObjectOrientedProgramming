/*==========================================

第一題-Template

==========================================*/

#include <iostream>
using namespace std;

// InsertionSort with template
template <typename T>
void InsertionSort(T list[], int listSize)
{
    for (int i = 1; i < listSize; i++)
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

// BinarySearch with template
template <typename T>
int BinarySearch(const T list[], T key, int listSize)
{
    int low = 0;
    int high = listSize - 1;

    while (high >= low)
    {
        int mid = (low + high) / 2;
        if (key < list[mid])
            high = mid - 1;
        else if (key == list[mid])
            return mid;
        else
            low = mid + 1;
    }

    return -1;
}

// 主程式
int main()
{
    // 宣告一個陣列大小
    const int SIZE = 9;
    // 宣告一個int陣列與一個double陣列
    int input1[3];
    double input2[3];

    // 將前三個輸入值存入int陣列
    for (int i = 0; i < 3; i++)
        cin >> input1[i];
    // 將後三個輸入值存入double陣列
    for (int i = 0; i < 3; i++)
        cin >> input2[i];

    //根據題目建立list1
    int list1[SIZE] = {1, 5, 6, 2, 3, 7, 9, 8, 4};
    // 印出原本陣列
    cout << "From: ";
    for (int i = 0; i < SIZE - 1; i++)
        cout << list1[i] << ",";
    cout << list1[SIZE - 1];
    // 進行 InsertionSort
    InsertionSort(list1, SIZE);
    // 印出排序完陣列
    cout << "\nTo: ";
    for (int i = 0; i < SIZE - 1; i++)
        cout << list1[i] << ",";
    cout << list1[SIZE - 1] << "\n";
    // 透過 BinarySearch 找尋輸入值位置
    cout << input1[0] << " at " << BinarySearch(list1, input1[0], SIZE) << "\n";
    cout << input1[1] << " at " << BinarySearch(list1, input1[1], SIZE) << "\n";
    cout << input1[2] << " at " << BinarySearch(list1, input1[2], SIZE) << "\n\n";

    //根據題目建立list2
    double list2[SIZE] = {1.1, 5.5, 6.6, 2.2, 3.3, 7.7, 9.9, 8.8, 4.4};
    // 印出原本陣列
    cout << "From: ";
    for (int i = 0; i < SIZE - 1; i++)
        cout << list2[i] << ",";
    cout << list2[SIZE - 1];
    // 進行 InsertionSort
    InsertionSort(list2, SIZE);
    // 印出排序完陣列
    cout << "\nTo: ";
    for (int i = 0; i < SIZE - 1; i++)
        cout << list2[i] << ",";
    cout << list2[SIZE - 1] << "\n";
    // 透過 BinarySearch 找尋輸入值位置
    cout << input2[0] << " at " << BinarySearch(list2, input2[0], SIZE) << "\n";
    cout << input2[1] << " at " << BinarySearch(list2, input2[1], SIZE) << "\n";
    cout << input2[2] << " at " << BinarySearch(list2, input2[2], SIZE) << "\n\n";

    return 0;
}