/*==========================================

第一題-Rational operator

==========================================*/

#include <iostream>
#include <string>  // 會用到 string
#include <sstream> // 會用到 stringstream
using namespace std;

// Rational 類別
class Rational
{
public:
    // 預設建構子
    Rational();
    // 一個參數建構子
    Rational(int numerator);
    // 二個參數建構子
    Rational(int numerator, int denominator);
    // 取得分子函式
    int getNumerator() const;
    // 取得分母函式
    int getDenominator() const;
    // 加法函式
    Rational add(const Rational &secondRational) const;
    // 減法函式
    Rational subtract(const Rational &secondRational) const;
    // 乘法函式
    Rational multiply(const Rational &secondRational) const;
    // 除法函式
    Rational divide(const Rational &secondRational) const;
    // 比較函式
    int compareTo(const Rational &secondRational) const;
    // 是否相等函式
    bool equals(const Rational &secondRational) const;
    // 取得計算後之整數值函式
    int intValue() const;
    // 取得計算後之浮點數值函式
    double doubleValue() const;
    // 輸出函式
    string toString() const;
    // operator += 函式
    Rational &operator+=(const Rational &secondRational);
    // operator -= 函式
    Rational &operator-=(const Rational &secondRational);
    // operator *= 函式
    Rational &operator*=(const Rational &secondRational);
    // operator /= 函式
    Rational &operator/=(const Rational &secondRational);
    // operator [] 函式
    int &operator[](int index);
    // operator 前++ 函式
    Rational &operator++();
    // operator 前-- 函式
    Rational &operator--();
    // operator 後++ 函式
    Rational operator++(int dummy);
    // operator 後-- 函式
    Rational operator--(int dummy);
    // operator 正號 函式
    Rational operator+();
    // operator 負號 函式
    Rational operator-();
    // operator 輸出符號 函式
    friend ostream &operator<<(ostream &, const Rational &);
    // operator 輸入符號 函式
    friend istream &operator>>(istream &, Rational &);

private:
    // 資料欄位(data fields) 為 private，分別有分子、分母、最大公因數函式
    int numerator;
    int denominator;
    static int gcd(int n, int d);
};

// operator 小於函式
bool operator<(const Rational &r1, const Rational &r2);
// operator 小於等於函式
bool operator<=(const Rational &r1, const Rational &r2);
// operator 大於函式
bool operator>(const Rational &r1, const Rational &r2);
// operator 大於等於函式
bool operator>=(const Rational &r1, const Rational &r2);
// operator 相等函式
bool operator==(const Rational &r1, const Rational &r2);
// operator 不相等函式
bool operator!=(const Rational &r1, const Rational &r2);
// operator 加法函式
Rational operator+(const Rational &r1, const Rational &r2);
// operator 減法函式
Rational operator-(const Rational &r1, const Rational &r2);
// operator 乘法函式
Rational operator*(const Rational &r1, const Rational &r2);
// operator 除法函式
Rational operator/(const Rational &r1, const Rational &r2);

// 預設建構子實作
Rational::Rational()
{
    numerator = 0;
    denominator = 1;
}
// 一個參數建構子實作
Rational::Rational(int numerator)
{
    this->numerator = numerator;
    this->denominator = 1;
}
// 二個參數建構子實作
Rational::Rational(int numerator, int denominator)
{
    int factor = gcd(numerator, denominator);
    this->numerator = (denominator > 0 ? 1 : -1) * numerator / factor;
    this->denominator = abs(denominator) / factor;
}
// 取得分子函式
int Rational::getNumerator() const
{
    return numerator;
}
// 取得分母函式實作
int Rational::getDenominator() const
{
    return denominator;
}
// 最大公因數函式實作
int Rational::gcd(int n, int d)
{
    int n1 = abs(n);
    int n2 = abs(d);
    int gcd = 1;

    for (int k = 1; k <= n1 && k <= n2; k++)
    {
        if (n1 % k == 0 && n2 % k == 0)
            gcd = k;
    }

    return gcd;
}
// 加法函式實作
Rational Rational::add(const Rational &secondRational) const
{
    int n = numerator * secondRational.getDenominator() +
            denominator * secondRational.getNumerator();
    int d = denominator * secondRational.getDenominator();
    return Rational(n, d);
}
// 減法函式實作
Rational Rational::subtract(const Rational &secondRational) const
{
    int n = numerator * secondRational.getDenominator() - denominator * secondRational.getNumerator();
    int d = denominator * secondRational.getDenominator();
    return Rational(n, d);
}
// 乘法函式實作
Rational Rational::multiply(const Rational &secondRational) const
{
    int n = numerator * secondRational.getNumerator();
    int d = denominator * secondRational.getDenominator();
    return Rational(n, d);
}
// 除法函式實作
Rational Rational::divide(const Rational &secondRational) const
{
    int n = numerator * secondRational.getDenominator();
    int d = denominator * secondRational.numerator;
    return Rational(n, d);
}
// 比較函式實作
int Rational::compareTo(const Rational &secondRational) const
{
    Rational temp = subtract(secondRational);
    if (temp.getNumerator() < 0)
        return -1;
    else if (temp.getNumerator() == 0)
        return 0;
    else
        return 1;
}
// 是否相等函式實作
bool Rational::equals(const Rational &secondRational) const
{
    if (compareTo(secondRational) == 0)
        return true;
    else
        return false;
}
// 取得計算後之整數值函式實作
int Rational::intValue() const
{
    return getNumerator() / getDenominator();
}
// 取得計算後之浮點數值函式實作
double Rational::doubleValue() const
{
    return 1.0 * getNumerator() / getDenominator();
}
// 輸出函式實作
string Rational::toString() const
{
    stringstream ss;
    ss << numerator;

    if (denominator > 1)
        ss << "/" << denominator;

    return ss.str();
}
// operator += 函式實作
Rational &Rational::operator+=(const Rational &secondRational)
{
    *this = add(secondRational);
    return *this;
}
// operator -= 函式實作
Rational &Rational::operator-=(const Rational &secondRational)
{
    *this = subtract(secondRational);
    return *this;
}
// operator *= 函式實作
Rational &Rational::operator*=(const Rational &secondRational)
{
    *this = multiply(secondRational);
    return *this;
}
// operator /= 函式實作
Rational &Rational::operator/=(const Rational &secondRational)
{
    *this = divide(secondRational);
    return *this;
}
// operator [] 函式實作
int &Rational::operator[](int index)
{
    if (index == 0)
        return numerator;
    else
        return denominator;
}
// operator 前++ 函式實作
Rational &Rational::operator++()
{
    numerator += denominator;
    return *this;
}
// operator 前-- 函式實作
Rational &Rational::operator--()
{
    numerator -= denominator;
    return *this;
}
// operator 後++ 函式實作
Rational Rational::operator++(int dummy)
{
    Rational temp(numerator, denominator);
    numerator += denominator;
    return temp;
}
// operator 後-- 函式實作
Rational Rational::operator--(int dummy)
{
    Rational temp(numerator, denominator);
    numerator -= denominator;
    return temp;
}
// operator 正號 函式實作
Rational Rational::operator+()
{
    return *this;
}
// operator 負號 函式實作
Rational Rational::operator-()
{
    return Rational(-numerator, denominator);
}
// operator 輸出符號 函式實作
ostream &operator<<(ostream &out, const Rational &rational)
{
    if (rational.denominator == 1)
        out << rational.numerator;
    else
        out << rational.numerator << "/" << rational.denominator;
    return out;
}
// operator 輸入符號 函式實作
istream &operator>>(istream &in, Rational &rational)
{
    cout << "Enter numerator: ";
    in >> rational.numerator;

    cout << "Enter denominator: ";
    in >> rational.denominator;
    return in;
}
// operator 小於函式實作
bool operator<(const Rational &r1, const Rational &r2)
{
    return (r1.compareTo(r2) < 0);
}
// operator 小於等於函式實作
bool operator<=(const Rational &r1, const Rational &r2)
{
    return (r1.compareTo(r2) <= 0);
}
// operator 大於函式實作
bool operator>(const Rational &r1, const Rational &r2)
{
    return (r1.compareTo(r2) > 0);
}
// operator 大於等於函式實作
bool operator>=(const Rational &r1, const Rational &r2)
{
    return (r1.compareTo(r2) >= 0);
}
// operator 相等函式實作
bool operator==(const Rational &r1, const Rational &r2)
{
    return (r1.compareTo(r2) == 0);
}
// operator 不相等函式實作
bool operator!=(const Rational &r1, const Rational &r2)
{
    return (r1.compareTo(r2) != 0);
}
// operator 加法函式實作
Rational operator+(const Rational &r1, const Rational &r2)
{
    return r1.add(r2);
}
// operator 減法函式實作
Rational operator-(const Rational &r1, const Rational &r2)
{
    return r1.subtract(r2);
}
// operator 乘法函式實作
Rational operator*(const Rational &r1, const Rational &r2)
{
    return r1.multiply(r2);
}
// operator 除法函式實作
Rational operator/(const Rational &r1, const Rational &r2)
{
    return r1.divide(r2);
}
// 主程式
int main()
{
    // 按題目需求宣告五個 Rational 物件
    Rational r1(2, 3);
    Rational r2(5, 7);
    Rational r3(3, 5);
    Rational r4(7, 2);
    Rational r5(5, 6);
    // 按題目需求進行計算
    Rational first = r1 + (r2 * r3);
    Rational second = (r4 - r5) / r2;
    // 按題目需求輸出
    cout << "first=" << first << endl;
    cout << "second=" << second << endl;
    cout << "++first=" << ++first << endl;
    cout << "--second=" << --second << endl;
    cout << first << ((first > second) ? ">" : ((first < second) ? "<" : "=")) << second << endl;

    return 0;
}