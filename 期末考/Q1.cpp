/*==========================================

第一題-Student Inheritance

==========================================*/

/* 本題重點：物件組合與繼承 */

#include <iostream>
#include <iomanip> // 將會用到 setprecision
#include <string>  // 將會用到 string
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

// Person 類別
class Person
{
public:
    // 預設建構子
    Person();
    // 設定名字
    void setName(string);
    // 設定生日
    void setBirthday(Date);
    // 取得名字
    string getName();
    // 取得生日
    Date getBirthday();

private:
    // 資料欄位(data fields) 為 private，分別有姓名、生日
    string name;
    Date birthday;
};
// 預設建構子實作
Person::Person()
{
}
// 設定名字實作
void Person::setName(string newName)
{
    name = newName;
}
// 設定生日實作
void Person::setBirthday(Date newBirthday)
{
    birthday = newBirthday;
}
// 取得名字實作
string Person::getName()
{
    return name;
}
// 取得生日實作
Date Person::getBirthday()
{
    return birthday;
}

// Student 類別
class Student : public Person
{
public:
    // 建構子
    Student(string, int, int, Date);
    // 設定數學成績
    void setMathScore(int);
    // 設定國文成績
    void setChineseScore(int);
    // 取得數學成績
    int getMathScore();
    // 取得國文成績
    int getChineseScore();
    // 取得平均成績
    double average();

private:
    // 資料欄位(data fields) 為 private，分別有數學成績、國文成績
    int mathScore, chineseScore;
};
// 建構子實作
Student::Student(string newName, int newMathScore, int newChineseScore, Date newBirthday)
{
    mathScore = newMathScore;
    chineseScore = newChineseScore;
    setName(newName);
    setBirthday(newBirthday);
}
// 設定數學成績實作
void Student::setMathScore(int newMathScore)
{
    mathScore = newMathScore;
}
// 設定國文成績實作
void Student::setChineseScore(int newChineseScore)
{
    chineseScore = newChineseScore;
}
// 取得數學成績實作
int Student::getMathScore()
{
    return mathScore;
}
// 取得國文成績實作
int Student::getChineseScore()
{
    return chineseScore;
}
// 取得平均成績實作
double Student::average()
{
    return (mathScore + chineseScore) / 2.0;
}

// 主程式
int main()
{
    // 根據題目宣告兩個 Student 物件
    Student s1("Candy", 70, 100, Date(1999, 6, 1));
    Student s2("Spotlight", 89, 60, Date(1997, 10, 8));

    // 設定小數點後一位
    cout << setprecision(1) << fixed;

    // 根據題目進行輸出
    cout << s1.getName() << " " << s1.getBirthday().getYear() << "-"
         << s1.getBirthday().getMonth() << "-" << s1.getBirthday().getDay() << " "
         << s1.average() << endl;
    cout << s2.getName() << " " << s2.getBirthday().getYear() << "-"
         << s2.getBirthday().getMonth() << "-" << s2.getBirthday().getDay() << " "
         << s2.average() << endl;

    return 0;
}