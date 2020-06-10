/*==========================================

第四題-C++多型

==========================================*/

#include <iostream>
#include <iomanip> // 將會運用到 setprecision
#include <string>  // 將會運用到 string
using namespace std;

// Shape 類別
class Shape
{
public:
    // 預設建構子
    Shape();
    // 帶有一個參數的建構子 (顏色)
    Shape(string);
    // 設定顏色函式
    void setColor(string);
    // 取得顏色函式
    string getColor();
    // 取得體積虛擬函式
    virtual double getVolume() = 0;
    // 輸出虛擬函式
    virtual string toString();

private:
    // 資料欄位(data fields) 為 private，分別有顏色
    string color;
};
// 預設建構子實作
Shape::Shape()
{
}
// 帶有一個參數的建構子實作
Shape::Shape(string newColor)
{
    color = newColor;
}
// 設定顏色函式實作
void Shape::setColor(string newColor)
{
    color = newColor;
}
// 取得顏色函式實作
string Shape::getColor()
{
    return color;
}
// 輸出函式實作
string Shape::toString()
{
    return "Shape";
}

// Sphere 類別 (繼承 Shape)
class Sphere : public Shape
{
public:
    // 帶有兩個參數的建構子 (半徑、顏色)
    Sphere(double, string);
    // 設定半徑函式
    void setRadius(double);
    // 取得半徑函式
    double getRadius();
    // 取得體積函式
    double getVolume();
    // 輸出函式
    string toString();

private:
    // 資料欄位(data fields) 為 private，分別有半徑
    double radius;
};
// 帶有兩個參數的建構子
Sphere::Sphere(double newRadius, string newColor)
{
    setRadius(newRadius);
    setColor(newColor);
}
// 設定半徑函式實作
void Sphere::setRadius(double newRadius)
{
    radius = newRadius;
}
// 取得半徑函式實作
double Sphere::getRadius()
{
    return radius;
}
// 取得體積函式實作
double Sphere::getVolume()
{
    return 4 * 3.14159 * radius * radius * radius / 3.0;
}
// 輸出函式實作
string Sphere::toString()
{
    return "Sphere";
}

// Cuboid 類別 (繼承 Shape)
class Cuboid : public Shape
{
public:
    // 帶有四個參數建構子 (長、寬、高、顏色)
    Cuboid(double, double, double, string);
    // 設定長函式
    void setLength(double);
    // 設定寬函式
    void setWidth(double);
    // 設定高函式
    void setHeight(double);
    // 取得長函式
    double getLength();
    // 取得寬函式
    double getWidth();
    // 取得高函式
    double getHeight();
    // 取得體積函式
    double getVolume();
    // 輸出函式
    string toString();

private:
    // 資料欄位(data fields) 為 private，分別有長、寬、高
    double length, width, height;
};
// 帶有四個參數建構子
Cuboid::Cuboid(double length, double width, double height, string color)
{
    setLength(length);
    setWidth(width);
    setHeight(height);
    setColor(color);
}
// 設定長函式
void Cuboid::setLength(double newLength)
{
    length = newLength;
}
// 設定寬函式
void Cuboid::setWidth(double newWidth)
{
    width = newWidth;
}
// 設定高函式
void Cuboid::setHeight(double newHeight)
{
    height = newHeight;
}
// 取得長函式
double Cuboid::getLength()
{
    return length;
}
// 取得寬函式
double Cuboid::getWidth()
{
    return width;
}
// 取得高函式
double Cuboid::getHeight()
{
    return height;
}
// 取得體積函式
double Cuboid::getVolume()
{
    return length * width * height;
}
// 輸出函式實作
string Cuboid::toString()
{
    return "Cuboid";
}

// 輸出函式
void display(Shape &s)
{
    // 將父類別動態轉型
    Shape *p = &s;
    Sphere *p1 = dynamic_cast<Sphere *>(p);
    Cuboid *p2 = dynamic_cast<Cuboid *>(p);

    // 假設是 Sphere
    if (p1 != NULL)
    {
        cout << s.toString() << ":(" << p1->getRadius() << ")," << setprecision(1) << fixed << s.getVolume() << "," << p1->getColor() << endl;
    }
    // 假設是 Cuboid
    if (p2 != NULL)
    {
        cout << s.toString() << setprecision(0) << fixed << ":(" << p2->getLength() << "," << p2->getWidth() << "," << p2->getHeight() << ")," << fixed << setprecision(1) << s.getVolume() << "," << p2->getColor() << endl;
    }
}
// 主程式
int main()
{
    // 宣告四個整數變數、兩個字串變數，為欲輸入值
    int radius, length, width, height;
    string sphereColor, cuboidColor;

    // 依序輸入
    cin >> radius >> sphereColor >> length >> width >> height >> cuboidColor;

    // 將輸入值建立兩個物件
    Sphere sphere(radius, sphereColor);
    Cuboid cuboid(length, width, height, cuboidColor);

    // 呼叫 display 函式輸出結果
    display(sphere);
    display(cuboid);

    return 0;
}