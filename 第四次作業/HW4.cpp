/*==========================================

第四次作業-繼承

==========================================*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Shape 類別
class Shape
{
public:
    Shape();
    Shape(const string &color, bool filled);
    string getColor();
    void setColor(string &color);
    bool isFilled() const;
    void setFilled(bool filled);
    virtual string toString() const;
    virtual double getArea() = 0;

private:
    string color;
    bool filled;
};

Shape::Shape()
{
    color = "white";
    filled = false;
}

Shape::Shape(const string &color, bool filled)
{
    this->color = color;
    this->filled = filled;
}

string Shape::getColor()
{
    return color;
}

void Shape::setColor(string &color)
{
    this->color = color;
}

bool Shape::isFilled() const
{
    return filled;
}

void Shape::setFilled(bool filled)
{
    this->filled = filled;
}

string Shape::toString() const
{
    return "Shape";
}

// Shape2D 類別
class Shape2D : public Shape
{
public:
    Shape2D();
    virtual double getPerimeter() = 0;
    virtual string toString() const;
};

Shape2D::Shape2D() {}

string Shape2D::toString() const
{
    return "Shape2D";
}

// Shape3D 類別
class Shape3D : public Shape
{
public:
    Shape3D();
    virtual double getVolume() = 0;
    virtual string toString() const;
};

Shape3D::Shape3D() {}

string Shape3D::toString() const
{
    return "Shape3D";
}

// Circle 類別
class Circle : public Shape2D
{
public:
    Circle();
    Circle(double);
    Circle(double radius, string color, bool filled);
    double getRadius() const;
    void setRadius(double);
    double getArea();
    double getPerimeter();
    virtual string toString() const;

private:
    double radius;
};

Circle::Circle()
{
    radius = 1;
}

Circle::Circle(double radius)
{
    setRadius(radius);
}

Circle::Circle(double radius, string color, bool filled)
{
    this->radius = radius;
    setColor(color);
    setFilled(filled);
}

double Circle::getRadius() const
{
    return radius;
}

void Circle::setRadius(double radius)
{
    this->radius = (radius >= 0) ? radius : 0;
}

double Circle::getArea()
{
    return radius * radius * 3.14159;
}

double Circle::getPerimeter()
{
    return 2 * radius * 3.14159;
}

string Circle::toString() const
{
    return "circle";
}

// Rectangle 類別
class Rectangle : public Shape2D
{
public:
    Rectangle();
    Rectangle(double width, double height);
    Rectangle(double width, double height, string color, bool filled);
    double getWidth() const;
    void setWidth(double);
    double getHeight() const;
    void setHeight(double);
    double getArea();
    double getPerimeter();
    virtual string toString() const;

private:
    double width;
    double height;
};

Rectangle::Rectangle()
{
    width = 1;
    height = 1;
}

Rectangle::Rectangle(double width, double height)
{
    setWidth(width);
    setHeight(height);
}

Rectangle::Rectangle(double width, double height, string color, bool filled)
{
    this->width = width;
    this->height = height;
    setColor(color);
    setFilled(filled);
}

double Rectangle::getWidth() const
{
    return width;
}

void Rectangle::setWidth(double width)
{
    this->width = (width >= 0) ? width : 0;
}

double Rectangle::getHeight() const
{
    return height;
}

void Rectangle::setHeight(double height)
{
    this->height = (height >= 0) ? height : 0;
}

double Rectangle::getArea()
{
    return width * height;
}

double Rectangle::getPerimeter()
{
    return 2 * (width + height);
}

string Rectangle::toString() const
{
    return "rectangle";
}

// Ball 類別
class Ball : public Shape3D
{
public:
    Ball();
    Ball(double, string, bool filled);
    double getRadius() const;
    void setRadius(double);
    double getArea();
    double getVolume();
    virtual string toString() const;

private:
    double radius;
};

Ball::Ball()
{
    radius = 1;
}

Ball::Ball(double radius, string color, bool filled)
{
    this->radius = radius;
    setColor(color);
    setFilled(filled);
}

double Ball::getRadius() const
{
    return radius;
}

void Ball::setRadius(double r)
{
    this->radius = (radius >= 0) ? radius : 0;
}

double Ball::getArea()
{
    return 4 * 3.14159 * radius * radius;
}

double Ball::getVolume()
{
    return 3.14159 * radius * radius * radius * 4 / 3;
}

string Ball::toString() const
{
    return "ball";
}

// Cube 類別
class Cube : public Shape3D
{
public:
    Cube();
    Cube(double, string, bool filled);
    double getSide() const;
    void setSide(double);
    double getArea();
    double getVolume();
    virtual string toString() const;

private:
    double side;
};

Cube::Cube()
{
    side = 1;
}

Cube::Cube(double side, string color, bool filled)
{
    this->side = side;
    setColor(color);
    setFilled(filled);
}

double Cube::getSide() const
{
    return side;
}

void Cube::setSide(double side)
{
    this->side = (side >= 0) ? side : 0;
}

double Cube::getArea()
{
    return 6 * side * side;
}

double Cube::getVolume()
{
    return side * side * side;
}

string Cube::toString() const
{
    return "cube";
}

// 判斷面積是否相等
bool equalArea(Shape &s1, Shape &s2)
{
    return s1.getArea() == s2.getArea();
}

// 判斷體積是否相等
bool equalVolume(Shape3D &s1, Shape3D &s2)
{
    return s1.getVolume() == s2.getVolume();
}

// 判斷周長是否相等
bool equalPerimeter(Shape2D &s1, Shape2D &s2)
{
    return s1.getPerimeter() == s2.getPerimeter();
}

// 輸出
void display(Shape &g)
{
    Shape *p = &g;
    Circle *p1 = dynamic_cast<Circle *>(p);
    Rectangle *p2 = dynamic_cast<Rectangle *>(p);
    Ball *p3 = dynamic_cast<Ball *>(p);
    Cube *p4 = dynamic_cast<Cube *>(p);

    if (p1 != NULL)
    {
        cout << p1->toString() << ", " << setprecision(0) << p1->getRadius() << ", " << p1->getColor() << ", "
             << setprecision(2) << fixed << p1->getArea() << endl;
    }

    if (p2 != NULL)
    {
        cout << p2->toString() << ", " << setprecision(0) << fixed << p2->getWidth() << ", "
             << p2->getHeight() << ", " << p2->getColor() << setprecision(2) << ", " << p2->getArea() << endl;
    }

    if (p3 != NULL)
    {
        cout << p3->toString() << ", " << setprecision(0) << p3->getRadius() << ", " << p3->getColor() << ", "
             << setprecision(2) << fixed << p3->getArea() << endl;
    }

    if (p4 != NULL)
    {
        cout << p4->toString() << ", " << setprecision(0) << fixed << p4->getSide() << ", "
             << p4->getColor() << ", " << setprecision(2) << fixed << p4->getArea() << endl;
    }
}

// 主程式
int main()
{
    Circle circle(5, "yellow", 1);
    display(circle);

    Rectangle rectangle(3, 4, "red", 0);
    display(rectangle);

    Ball ball(5, "blue", 1);
    display(ball);

    Cube cube(4, "black", 0);
    display(cube);

    cout << circle.toString() << " " << circle.getPerimeter() << (equalPerimeter(circle, rectangle) ? " == " : " != ") << rectangle.toString() << " " << rectangle.getPerimeter() << endl;

    cout << ball.toString() << " " << ball.getVolume() << (equalVolume(ball, cube) ? " == " : " != ") << cube.toString() << " " << cube.getVolume() << endl;

    return 0;
}