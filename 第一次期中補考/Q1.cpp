/*==========================================

期中補考第一題

==========================================*/

#include <iostream>
using namespace std;

// Employee 類別
class Employee
{
public:
    // 預設建構子
    Employee();
    // 四個輸入參數建構子
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
    string getName() const;
    // 取得職位
    string getPosition() const;
    // 取得日薪
    int getWage() const;
    // 取得工作天
    int getDays() const;
    // 取得總收入
    int getIncome() const;
    // 輸出函式
    void print();
    // 取得員工人數
    static int getNumOfEmployee();

private:
    // 資料欄位(data fields) 為 private，分別有名字、職位、日薪、工作天、員工人數
    string name, position;
    int wage, days;
    static int numOfEmployee;
};
// 初始化員工人數
int Employee::numOfEmployee = 0;
// 預設建構子實作
Employee::Employee()
{
    numOfEmployee++;
}
// 四個輸入參數建構子實作
Employee::Employee(string newName, string newPosition, int newWage, int newDays)
{
    name = newName;
    position = newPosition;
    wage = newWage;
    days = newDays;
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
// 取得總收入實作
int Employee::getIncome() const
{
    return wage * days;
}
// 輸出函式實作
void Employee::print()
{
    cout << getPosition() << "-" << getName() << " " << getIncome() << endl;
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
    // 宣告欲輸入的三個值，分別為日薪、工作天、職位
    int wage, days;
    string position;
    // 根據題目要求，宣告四個物件
    Employee employee1("Linda", "Chairman", 10000, 15);
    Employee employee2("Superstar", "President", 8000, 20);
    Employee employee3("Spotlight", "Director", 6000, 22);
    Employee employee4("Candy", "Consultant", 5500, 28);
    // 將四個物件存入物件陣列
    Employee empArray[SIZE] = {employee1, employee2, employee3, employee4};
    // 輸入值
    cin >> wage >> position >> days;
    // 根據題目進行修改
    empArray[0].setWage(wage);
    empArray[1].setPosition(position);
    empArray[2].setDays(days);
    empArray[3].setDays(days);
    // 將四個物件使用print函式根據題目要求格式輸出
    for (int i = 0; i < SIZE; i++)
        empArray[i].print();
    // 輸出員工人數
    cout << "The firm has " << Employee::getNumOfEmployee() << " employees." << endl;
    // 輸出員工平均薪資
    cout << "Their average salary is " << average(empArray, SIZE) << " dollars." << endl;

    return 0;
}