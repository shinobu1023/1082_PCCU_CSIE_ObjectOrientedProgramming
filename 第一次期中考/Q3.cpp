/*==========================================

期中考第三題

==========================================*/

/* 本題重點：print function */

#include <iostream>
using namespace std;

// Employee 類別
class Employee
{
public:
    // 建構子
    Employee(string, string, int, int);
    // 設定名字
    void setName(string);
    // 設定職位
    void setPosition(string);
    // 設定日薪
    void setWage(int);
    // 設定工作天
    void setDays(int);
    // 取得名字
    string getName();
    // 取得職位
    string getPosition();
    // 取得日薪
    int getWage();
    // 取得工作天
    int getDays();
    // 取得總收入
    int getIncome();
    // 輸出函式
    void print();

private:
    // 資料欄位(data fields) 為 private，分別有名字、職位、日薪、工作天
    string name, position;
    int wage, days;
};
// 建構子實作
Employee::Employee(string newName, string newPosition, int newWage, int newDays)
{
    name = newName;
    position = newPosition;
    wage = newWage;
    days = newDays;
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
// 取得名字實作
string Employee::getName()
{
    return name;
}
// 取得職位實作
string Employee::getPosition()
{
    return position;
}
// 取得日薪實作
int Employee::getWage()
{
    return wage;
}
// 取得工作天實作
int Employee::getDays()
{
    return days;
}
// 取得總收入實作
int Employee::getIncome()
{
    return wage * days;
}
// 輸出函式實作
void Employee::print()
{
    cout << getPosition() << "-" << getName() << " " << getIncome() << endl;
}
// 主程式
int main()
{
    // 宣告欲輸入的三個值，分別為日薪、工作天、職位
    int wage, days;
    string position;
    // 根據題目要求，宣告四個物件
    Employee employee1("Linda", "Chairman", 10000, 15);
    Employee employee2("Superstar", "President", 8000, 20);
    Employee employee3("Spotlight", "Director", 6000, 22);
    Employee employee4("Candy", "Consultant", 5500, 28);
    // 輸入值
    cin >> wage >> position >> days;
    // 根據題目進行修改
    employee1.setWage(wage);
    employee2.setPosition(position);
    employee3.setDays(days);
    employee4.setDays(days);
    // 將四個物件使用print函式根據題目要求格式輸出
    employee1.print();
    employee2.print();
    employee3.print();
    employee4.print();

    return 0;
}