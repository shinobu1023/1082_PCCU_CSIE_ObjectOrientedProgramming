/*==========================================

第一題-Employee Swap function in class

==========================================*/

/* 本題重點： 物件 Reference 交換、物件 Pointer 交換 */

#include <iostream>
#include <iomanip> // 將會使用到 setprecision
#include <string>
using namespace std;

// Employee 類別
class Employee
{
public:
    // 建構子
    Employee(string newName, int newIncome, int newHours);
    // 設定姓名
    void setName(string newName);
    // 設定日薪
    void setIncome(int newIncome);
    // 設定工時
    void setHours(int newHours);
    // 取得姓名
    string getName();
    // 取得日薪
    int getIncome();
    // 取得工時
    int getHours();
    // 取得時薪
    double getWage();
    // 透過 Reference 交換
    void swapByReference(Employee &r2);
    // 透過 Pointer 交換
    void swapByPointer(Employee *p2);

private:
    // 資料欄位(data fields) 為 private，分別有姓名、日薪、工時
    string name;
    int income;
    int hours;
};
// 建構子實作
Employee::Employee(string newName, int newIncome, int newHours)
{
    name = newName;
    income = newIncome;
    hours = newHours;
}
// 設定姓名實作
void Employee::setName(string newName)
{
    name = newName;
}
// 設定日薪實作
void Employee::setIncome(int newIncome)
{
    income = newIncome;
}
// 設定工時實作
void Employee::setHours(int newHours)
{
    hours = newHours;
}
// 取得姓名實作
string Employee::getName()
{
    return name;
}
// 取得日薪實作
int Employee::getIncome()
{
    return income;
}
// 取得工時實作
int Employee::getHours()
{
    return hours;
}
// 取得時薪實作
double Employee::getWage()
{
    return income / (hours * 1.0);
}
// 透過 Reference 交換實作
void Employee::swapByReference(Employee &r2)
{
    Employee temp = *this;
    *this = r2;
    r2 = temp;
}
// 透過 Pointer 交換實作
void Employee::swapByPointer(Employee *p2)
{
    Employee temp = *this;
    *this = *p2;
    *p2 = temp;
}
// 主程式
int main()
{
    // 宣告六個欲輸入的值，分別為兩組姓名、兩組日薪、兩組工時
    string name_1, name_2;
    int income_1, income_2;
    int hours_1, hours_2;
    // 輸入值
    cin >> name_1 >> income_1 >> hours_1 >> name_2 >> income_2 >> hours_2;
    // 宣告兩個物件
    Employee employee1(name_1, income_1, hours_1);
    Employee employee2(name_2, income_2, hours_2);
    // 進行 Reference 交換
    cout << "SwapByReference:" << employee1.getName() << "-" << fixed << setprecision(2) << employee1.getWage()
         << " " << employee2.getName() << "-" << employee2.getWage();
    employee1.swapByReference(employee2);
    cout << " to " << employee1.getName() << "-" << employee1.getWage()
         << " " << employee2.getName() << "-" << employee2.getWage() << endl;
    // 進行 Pointer 交換
    cout << "SwapByPointer:" << employee1.getName() << "-" << employee1.getWage()
         << " " << employee2.getName() << "-" << employee2.getWage();
    employee1.swapByPointer(&employee2);
    cout << " to " << employee1.getName() << "-" << employee1.getWage()
         << " " << employee2.getName() << "-" << employee2.getWage() << endl;

    return 0;
}