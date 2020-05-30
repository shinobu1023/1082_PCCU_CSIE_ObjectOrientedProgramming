/*==========================================

第一題-Polymorphism

==========================================*/

#include <iostream>
#include <string>
#include <iomanip> // 將會使用 setprecision
using namespace std;

// GeometricObject 類別
class GeometricObject
{
public:
    // 預設建構子
    GeometricObject();
    // 帶一個參數的建構子
    GeometricObject(const string &color);
    // 設定顏色
    void setColor(const string &color);
    // 取得顏色
    string getColor() const;
    // 取得面積 (virtual)
    virtual double getArea() = 0;
    // 取得體積 (virtual)
    virtual double getVolume() = 0;

private:
    // 資料欄位(data fields) 為 private，為顏色
    string color;
};
// 預設建構子實作
GeometricObject::GeometricObject()
{
    color = "white";
}
// 帶一個參數的建構子實作
GeometricObject::GeometricObject(const string &color)
{
    this->color = color;
}
// 設定顏色實作
void GeometricObject::setColor(const string &color)
{
    this->color = color;
}
// 取得顏色實作
string GeometricObject::getColor() const
{
    return color;
}
// Ball 類別 (繼承 GeometricObject)
class Ball : public GeometricObject
{
public:
    // 建構子
    Ball(double, const string &);
    // 設定半徑
    void setRadius(double);
    // 取得半徑
    double getRadius() const;
    // 取得面積
    double getArea();
    // 取得體積
    double getVolume();

private:
    // 資料欄位(data fields) 為 private，為半徑
    double radius;
};
// 建構子實作
Ball::Ball(double r, const string &color)
{
    this->radius = r;
    setColor(color);
}
// 設定半徑實作
void Ball::setRadius(double r)
{
    this->radius = (r >= 0) ? r : 0;
}
// 取得半徑實作
double Ball::getRadius() const
{
    return radius;
}
// 取得面積實作
double Ball::getArea()
{
    return 4 * 3.14159 * radius * radius;
}
// 取得體積實作
double Ball::getVolume()
{
    return 3.14159 * radius * radius * radius * 4 / 3;
}
// Cube 類別 (繼承 GeometricObject)
class Cube : public GeometricObject
{
public:
    // 建構子
    Cube(double, const string &);
    // 設定邊長
    void setSide(double);
    // 取得邊長
    double getSide() const;
    // 取得面積
    double getArea();
    // 取得體積
    double getVolume();

private:
    // 資料欄位(data fields) 為 private，為邊長
    double side;
};
// 建構子實作實作
Cube::Cube(double L, const string &color)
{
    this->side = L;
    setColor(color);
}
// 設定邊長實作
void Cube::setSide(double L)
{
    this->side = (L >= 0) ? L : 0;
}
// 取得邊長實作
double Cube::getSide() const
{
    return side;
}
// 取得面積實作
double Cube::getArea()
{
    return 6 * side * side;
}
// 取得體積實作
double Cube::getVolume()
{
    return side * side * side;
}
//輸出函式
void display(GeometricObject &g)
{
    cout << ", area:" << g.getArea() << ", volume:" << g.getVolume() << ", color:" << g.getColor() << endl;
}
// 主程式
int main()
{
    // 宣告四個欲輸入值的變數，半徑、邊長、兩個顏色
    int radius, length;
    string bullColor, cubeColor;
    // 輸入
    cin >> radius >> bullColor >> length >> cubeColor;
    // 宣告兩個物件
    Ball ball(radius, bullColor);
    Cube cube(length, cubeColor);
    // 輸出
    cout << setprecision(1) << fixed;
    cout << "Ball\nradius:" << ball.getRadius();
    display(ball);
    cout << "Cube\nlength:" << cube.getSide();
    display(cube);

    return 0;
}