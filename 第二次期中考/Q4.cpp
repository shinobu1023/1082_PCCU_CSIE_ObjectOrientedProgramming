/*==========================================

第四題-Complex function

==========================================*/

/* 本題重點： 撰寫類別透過函式進行運算  */

#include <iostream>
#include <string>  // 將會使用到 string
#include <sstream> // 將會使用到 stringstream
using namespace std;

// Complex 類別
class Complex
{
public:
    // 建構子
    Complex(int, int);
    // 取得整數數字
    int getIntNumber() const;
    // 取得虛數數字
    int getComplexNumber() const;
    // 加法
    Complex add(const Complex &) const;
    // 減法
    Complex subtract(const Complex &) const;
    // 輸出字串
    string toString() const;

private:
    // 資料欄位(data fields) 為 private，分別有整數、虛數
    int intNumber;
    int complexNumber;
};
// 建構子實作
Complex::Complex(int a, int b)
{
    intNumber = a;
    complexNumber = b;
}
// 取得整數數字實作
int Complex::getIntNumber() const
{
    return intNumber;
}
// 取得虛數數字實作
int Complex::getComplexNumber() const
{
    return complexNumber;
}
// 加法實作
Complex Complex::add(const Complex &secondComplex) const
{
    int n = intNumber + secondComplex.getIntNumber();
    int d = complexNumber + secondComplex.getComplexNumber();
    return Complex(n, d);
}
// 減法實作
Complex Complex::subtract(const Complex &secondComplex) const
{
    int n = intNumber - secondComplex.getIntNumber();
    int d = complexNumber - secondComplex.getComplexNumber();
    return Complex(n, d);
}
// 輸出字串實作
string Complex::toString() const
{
    stringstream ss;
    ss << "(" << intNumber;
    ss << "+" << complexNumber << "i)";

    return ss.str();
}
// 主程式
int main()
{
    // 宣告兩個陣列，分別存三組的整數與虛數
    int x[3], y[3];
    // 使用迴圈輸入三組值
    for (int i = 0; i < 3; i++)
        cin >> x[i] >> y[i];
    // 建立三個虛數物件
    Complex comp1(x[0], y[0]);
    Complex comp2(x[1], y[1]);
    Complex comp3(x[2], y[2]);
    // 計算與輸出
    cout << comp1.toString() << "-" << comp2.toString() << "+" << comp3.toString() << "=" << (comp1.subtract(comp2)).add(comp3).toString() << endl;

    return 0;
}