/*==========================================

期中考第五題

==========================================*/

/* 本題重點：物件組合、物件組合修改值、物件組合 print */

#include <iostream>
#include <iomanip> // 將會使用到 setprecision
using namespace std;

// Date 類別
class Date
{
public:
    // 預設建構子
    Date();
    // 三個輸入參數建構子
    Date(int, int, int);
    // 設定年
    void setYear(int);
    // 設定月
    void setMonth(int);
    // 設定日
    void setDay(int);
    // 取得年
    int getYear();
    // 取得月
    int getMonth();
    // 取得日
    int getDay();
    // 輸出函式
    void print();

private:
    // 資料欄位(data fields) 為 private，分別有年、月、日
    int year, month, day;
};
// 預設建構子實作
Date::Date()
{
}
// 三個輸入參數建構子實作
Date::Date(int newYear, int newMonth, int newDay)
{
    year = newYear;
    month = newMonth;
    day = newDay;
}
// 設定年實作
void Date::setYear(int newYear)
{
    year = newYear;
}
// 設定月實作
void Date::setMonth(int newMonth)
{
    month = newMonth;
}
// 設定日實作
void Date::setDay(int newDay)
{
    day = newDay;
}
// 取得年實作
int Date::getYear()
{
    return year;
}
// 取得月實作
int Date::getMonth()
{
    return month;
}
// 取得日實作
int Date::getDay()
{
    return day;
}
// 輸出函式實作
void Date::print()
{
    cout << getYear() << "/" << getMonth() << "/" << getDay() << " ";
}

// BMI 類別
class BMI
{
public:
    // 預設建構子
    BMI();
    // 兩個輸入參數建構子
    BMI(double, double);
    // 設定身高
    void setHeight(double);
    // 設定體重
    void setWeight(double);
    // 取得身高
    double getHeight();
    // 取得體重
    double getWeight();
    // 輸出函式
    void print();

private:
    // 資料欄位(data fields) 為 private，分別有身高、體重
    double height, weight;
};
// 預設建構子實作
BMI::BMI()
{
}
// 兩個輸入參數建構子實作
BMI::BMI(double newHeight, double newWeight)
{
    height = newHeight;
    weight = newWeight;
}
// 設定身高實作
void BMI::setHeight(double newHeight)
{
    height = newHeight;
}
// 設定體重實作
void BMI::setWeight(double newWeight)
{
    weight = newWeight;
}
// 取得身高實作
double BMI::getHeight()
{
    return height;
}
// 取得體重實作
double BMI::getWeight()
{
    return weight;
}
// 輸出函式實作
void BMI::print()
{
    cout << setprecision(2) << fixed << getWeight() / (getHeight() * getHeight()) << endl;
}

// Student 類別
class Student
{
public:
    // 建構子
    Student(string, Date, BMI);
    // 設定名字
    void setName(string);
    // 設定生日
    void setBirthday(Date);
    // 設定BMI
    void setBmi(BMI);
    // 取得名字
    string getName();
    // 取得生日
    Date getBirthday();
    // 取得BMI
    BMI getBmi();
    // 輸出函式
    void print();

private:
    // 資料欄位(data fields) 為 private，分別有姓名、生日、BMI
    string name;
    Date birthday;
    BMI bmi;
};
// 建構子實作
Student::Student(string newName, Date newDate, BMI newBmi)
{
    name = newName;
    birthday = newDate;
    bmi = newBmi;
}
// 設定名字實作
void Student::setName(string newName)
{
    name = newName;
}
// 設定生日實作
void Student::setBirthday(Date newDate)
{
    birthday = newDate;
}
// 設定BMI實作
void Student::setBmi(BMI newBmi)
{
    bmi = newBmi;
}
// 取得名字實作
string Student::getName()
{
    return name;
}
// 取得生日實作
Date Student::getBirthday()
{
    return birthday;
}
// 取得BMI實作
BMI Student::getBmi()
{
    return bmi;
}
// 輸出函式實作
void Student::print()
{
    cout << getName() << " ";
    getBirthday().print();
    getBmi().print();
}
// 主程式
int main()
{
    // 宣告欲輸入的四個值，分別為姓名、年、月、體重
    string name;
    int year, day;
    double weight;
    // 根據題目要求，宣告三個Student物件
    Student student1("Candy", Date(1999, 6, 1), BMI(1.6, 60.5));
    Student student2("Sunny", Date(1997, 11, 19), BMI(1.7, 50.0));
    Student student3("Spotlight", Date(1998, 10, 8), BMI(1.7, 55.2));
    // 輸入值
    cin >> name >> year >> day >> weight;
    // 根據題目進行修改
    student1.setName(name);
    student1.setBmi(BMI(1.6, weight));
    student2.setBirthday(Date(year, 11, 19));
    student3.setBirthday(Date(1998, 10, day));
    student3.setBmi(BMI(1.7, weight));
    // 將三個物件使用print函式根據題目要求格式輸出
    student1.print();
    student2.print();
    student3.print();

    return 0;
}