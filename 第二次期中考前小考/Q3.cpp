/*==========================================

第三題-Point

==========================================*/

#include <iostream>
#include <string> // 將會使用到字串
#include <sstream> // 將會使用到 stringstream
using namespace std;

// Point 類別
class Point
{
public:
    // 建構子
    Point(int, int);
    // 取得第一個數函式
    int getFirstNumber();
    // 取得第二個數函式
    int getSecondNumber();
    // 加法函式
    Point add(Point);
    // 減法函式
    Point subtract(Point);
    // 輸出函式
    string toString();

private:
    // 資料欄位(data fields) 為 private，分別第一個數(x值)、第二個數(y值)
    int firstNumber;
    int secondNumber;
};

// 建構子實作
Point::Point(int a, int b)
{
    firstNumber = a;
    secondNumber = b;
}
// 取得第一個數函式實作
int Point::getFirstNumber()
{
    return firstNumber;
}
// 取得第二個數函式實作
int Point::getSecondNumber()
{
    return secondNumber;
}
// 加法函式實作
Point Point::add(Point secondPoint)
{
    int n = firstNumber + secondPoint.getFirstNumber();
    int d = secondNumber + secondPoint.getSecondNumber();
    return Point(n, d);
}
// 減法函式實作
Point Point::subtract(Point secondPoint)
{
    int n = firstNumber - secondPoint.getFirstNumber();
    int d = secondNumber - secondPoint.getSecondNumber();
    return Point(n, d);
}
// 輸出函式實作
string Point::toString()
{
    stringstream ss;
    ss << "(" << firstNumber << "," << secondNumber << ")";

    return ss.str();
}
// 主程式
int main()
{
    // 宣告兩個陣列，分別存三組座標的x值、y值
    int x[3], y[3];
    // 使用迴圈輸入三組座標
    for (int i = 0; i < 3; i++)
        cin >> x[i] >> y[i];
    // 建立三個座標物件
    Point point1(x[0], y[0]);
    Point point2(x[1], y[1]);
    Point point3(x[2], y[2]);
    // 計算與輸出
    cout << point1.toString() << "+" << point2.toString() << "-" << point3.toString()
         << "=" << ((point1.add(point2)).subtract(point3)).toString() << endl;

    return 0;
}