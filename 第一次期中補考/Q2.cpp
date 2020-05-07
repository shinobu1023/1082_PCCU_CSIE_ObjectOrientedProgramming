/*==========================================

期中補考第二題

==========================================*/

#include <iostream>
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
    int getYear() const;
    // 取得月
    int getMonth() const;
    // 取得日
    int getDay() const;
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
int Date::getYear() const
{
    return year;
}
// 取得月實作
int Date::getMonth() const
{
    return month;
}
// 取得日實作
int Date::getDay() const
{
    return day;
}
// 輸出函式實作
void Date::print()
{
    cout << getYear() << "/" << getMonth() << "/" << getDay() << endl;
}

// Employee 類別
class Employee
{
public:
    // 預設建構子
    Employee();
    // 四個輸入參數建構子
    Employee(string, string, int, int, Date);
    // 設定名字
    void setName(string);
    // 設定職位
    void setPosition(string);
    // 設定日薪
    void setWage(int);
    // 設定工作天
    void setDays(int);
    // 設定生日
    void setBirthday(Date);
    // 取得名字
    string getName() const;
    // 取得職位
    string getPosition() const;
    // 取得日薪
    int getWage() const;
    // 取得工作天
    int getDays() const;
    // 取得生日
    Date getBirthday() const;
    // 取得總收入
    int getIncome() const;
    // 輸出函式
    void print();
    // 取得員工人數
    static int getNumOfEmployee();

private:
    // 資料欄位(data fields) 為 private，分別有名字、職位、日薪、工作天、員工人數、生日
    string name, position;
    int wage, days;
    static int numOfEmployee;
    Date birthday;
};
// 初始化員工人數
int Employee::numOfEmployee = 0;
// 預設建構子實作
Employee::Employee()
{
    numOfEmployee++;
}
// 四個輸入參數建構子實作
Employee::Employee(string newName, string newPosition, int newWage, int newDays, Date newBirthday)
{
    name = newName;
    position = newPosition;
    wage = newWage;
    days = newDays;
    birthday = newBirthday;
    numOfEmployee++;
}
// 設定名字實作
void Employee::setName(string newName)
{
    name = newName;
}
// 設定職位實作
void Employee::setPosition(string newPosition)
{
    position = newPosition;
}
// 設定日薪實作
void Employee::setWage(int newWage)
{
    wage = newWage;
}
// 設定工作天實作
void Employee::setDays(int newDays)
{
    days = newDays;
}
// 設定生日實作
void Employee::setBirthday(Date newBirthday)
{
    birthday = newBirthday;
}
// 取得名字實作
string Employee::getName() const
{
    return name;
}
// 取得職位實作
string Employee::getPosition() const
{
    return position;
}
// 取得日薪實作
int Employee::getWage() const
{
    return wage;
}
// 取得工作天實作
int Employee::getDays() const
{
    return days;
}
// 取得工作天實作
Date Employee::getBirthday() const
{
    return birthday;
}
// 取得總收入實作
int Employee::getIncome() const
{
    return wage * days;
}
// 輸出函式實作
void Employee::print()
{
    cout << getPosition() << "-" << getName() << " " << getIncome() << " ";
    birthday.print();
}
// 取得員工人數實作
int Employee::getNumOfEmployee()
{
    return numOfEmployee;
}
// 計算平均薪資函式
int average(Employee empArray[], int size)
{
    double sum = 0;

    for (int i = 0; i < size; i++)
        sum += empArray[i].getIncome();

    return sum / size;
}
// 主程式
int main()
{
    // 宣告一個陣列大小常數
    const int SIZE = 4;
    // 宣告欲輸入的三個值，分別為日薪、工作天、職位、年份
    int wage, days, year;
    string position;
    // 根據題目要求，宣告四個物件
    Employee employee1("Linda", "Chairman", 10000, 15, Date(1999, 6, 1));
    Employee employee2("Superstar", "President", 8000, 20, Date(1995, 4, 8));
    Employee employee3("Spotlight", "Director", 6000, 22, Date(1998, 8, 26));
    Employee employee4("Candy", "Consultant", 5500, 28, Date(1992, 10, 10));
    // 將四個物件存入物件陣列
    Employee empArray[SIZE] = {employee1, employee2, employee3, employee4};
    // 輸入值
    cin >> wage >> position >> days >> year;
    // 根據題目進行修改
    empArray[0].setWage(wage);
    empArray[1].setPosition(position);
    empArray[2].setDays(days);
    empArray[3].setDays(days);
    empArray[3].setBirthday(Date(year, 10, 10));
    // 將四個物件使用print函式根據題目要求格式輸出
    for (int i = 0; i < SIZE; i++)
        empArray[i].print();
    // 輸出員工人數
    cout << "The firm has " << Employee::getNumOfEmployee() << " employees." << endl;
    // 輸出員工平均薪資
    cout << "Their average salary is " << average(empArray, SIZE) << " dollars." << endl;

    return 0;
}