/*==========================================

第三次作業-Complex_operator

==========================================*/

#include <iostream>
#include <string>  // 將會使用到 string
#include <sstream> // 將會使用到 stringstream
using namespace std;

// Complex 類別
class Complex
{
public:
    // 預設建構子
    Complex();
    // 帶有兩個參數的建構子
    Complex(int, int);
    // 取得整數數字
    int getIntNumber() const;
    // 取得虛數數字
    int getComplexNumber() const;
    // 加法
    Complex add(const Complex &) const;
    // 減法
    Complex subtract(const Complex &) const;
    // 乘法
    Complex multiply(const Complex &) const;
    // 輸出字串
    string toString() const;
    // operator += 函式
    Complex &operator+=(const Complex &);
    // operator -= 函式
    Complex &operator-=(const Complex &);
    // operator *= 函式
    Complex &operator*=(const Complex &);
    // operator [] 函式
    int &operator[](int);
    // operator 前++ 函式
    Complex &operator++();
    // operator 前-- 函式
    Complex &operator--();
    // operator 後++ 函式
    Complex operator++(int);
    // operator 後-- 函式
    Complex operator--(int);
    // operator 正號 函式
    Complex operator+();
    // operator 負號 函式
    Complex operator-();
    // operator 輸出符號 函式
    friend ostream &operator<<(ostream &, const Complex &);
    // operator 輸入符號 函式
    friend istream &operator>>(istream &, Complex &);

private:
    // 資料欄位(data fields) 為 private，分別有整數、虛數
    int intNumber;
    int complexNumber;
};
// operator 加法函式
Complex operator+(const Complex &, const Complex &);
// operator 減法函式
Complex operator-(const Complex &, const Complex &);
// operator 乘法函式
Complex operator*(const Complex &, const Complex &);

// 預設建構子實作
Complex::Complex()
{
    intNumber = 1;
    complexNumber = 1;
}
// 兩個參數建構子實作
Complex::Complex(int newIntNumber, int newComplexNumber)
{
    intNumber = newIntNumber;
    complexNumber = newComplexNumber;
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
    int a = intNumber + secondComplex.intNumber;
    int b = complexNumber + secondComplex.complexNumber;
    return Complex(a, b);
}
// 減法實作
Complex Complex::subtract(const Complex &secondComplex) const
{
    int a = intNumber - secondComplex.intNumber;
    int b = complexNumber - secondComplex.complexNumber;
    return Complex(a, b);
}
// 乘法函式實作
Complex Complex::multiply(const Complex &secondComplex) const
{
    int a = (intNumber * secondComplex.intNumber) + (complexNumber * secondComplex.complexNumber * (-1));
    int b = (intNumber * secondComplex.complexNumber) + (complexNumber * secondComplex.intNumber);
    return Complex(a, b);
}
// 輸出函式實作
string Complex::toString() const
{
    stringstream ss;
    ss << intNumber;

    if (complexNumber > 0)
        ss << "+" << complexNumber << "i";
    else if (complexNumber < 0)
        ss << "-" << complexNumber << "i";

    return ss.str();
}
// operator += 函式實作
Complex &Complex::operator+=(const Complex &secondComplex)
{
    *this = add(secondComplex);
    return *this;
}
// operator -= 函式實作
Complex &Complex::operator-=(const Complex &secondComplex)
{
    *this = subtract(secondComplex);
    return *this;
}
// operator *= 函式實作
Complex &Complex::operator*=(const Complex &secondComplex)
{
    *this = multiply(secondComplex);
    return *this;
}
// operator [] 函式實作
int &Complex::operator[](int index)
{
    if (index == 0)
        return intNumber;
    else
        return complexNumber;
}
// operator 前++ 函式實作
Complex &Complex::operator++()
{
    intNumber++;
    return *this;
}
// operator 前-- 函式實作
Complex &Complex::operator--()
{
    intNumber--;
    return *this;
}
// operator 後++ 函式實作
Complex Complex::operator++(int dummy)
{
    Complex temp(intNumber, complexNumber);
    intNumber++;
    return temp;
}
// operator 後-- 函式實作
Complex Complex::operator--(int dummy)
{
    Complex temp(intNumber, complexNumber);
    intNumber--;
    return temp;
}
// operator 正號 函式實作
Complex Complex::operator+()
{
    return *this;
}
// operator 負號 函式實作
Complex Complex::operator-()
{
    return *this;
}
// operator 輸出符號 函式實作
ostream &operator<<(ostream &out, const Complex &secondComplex)
{
    if (secondComplex.complexNumber == 0)
        out << secondComplex.intNumber;
    else
        out << secondComplex.intNumber << secondComplex.complexNumber << "i";
    return out;
}
// operator 輸入符號 函式實作
istream &operator>>(istream &in, Complex &secondComplex)
{
    cout << "Enter intNumber: ";
    in >> secondComplex.intNumber;

    cout << "Enter complexNumber: ";
    in >> secondComplex.complexNumber;
    return in;
}
// operator 加法函式實作
Complex operator+(const Complex &r1, const Complex &r2)
{
    return r1.add(r2);
}
// operator 減法函式實作
Complex operator-(const Complex &r1, const Complex &r2)
{
    return r1.subtract(r2);
}
// operator 乘法函式實作
Complex operator*(const Complex &r1, const Complex &r2)
{
    return r1.multiply(r2);
}
// 主程式
int main()
{
    // 按題目需求宣告五個 Complex 物件
    Complex c1(3, 4);
    Complex c2(2, -4);
    Complex c3(3, -1);
    Complex c4(4, 3);
    Complex c5(5, 6);
    // 按題目需求進行計算
    Complex first = c1 + (c2 * c3);
    Complex second = c4 - c5;
    // 按題目需求輸出
    cout << "first=" << first << endl;
    cout << "second=" << second << endl;
    cout << "++first=" << ++first << endl;
    cout << "--second=" << --second << endl;

    return 0;
}