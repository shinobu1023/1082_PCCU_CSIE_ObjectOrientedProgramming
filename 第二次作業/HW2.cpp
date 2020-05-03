/*==========================================

第二次作業-學生成績資料卡

==========================================*/

#include <iostream>
#include <iomanip> // 將會使用到 setprecision
#include <string>  // 將會使用到 string
using namespace std;
// Date 類別
class Date
{
public:
    // 預設建構子
    Date();
    // 三個輸入參數建構子
    Date(int, int, int);
    // 設定月
    void setMonth(int);
    // 設定日
    void setDay(int);
    // 設定年
    void setYear(int);
    // 取得月
    int getMonth() const;
    // 取得日
    int getDay() const;
    // 取得年
    int getYear() const;

private:
    // 資料欄位(data fields) 為 private，分別有年、月、日
    int month, day, year;
};
// 預設建構子實作
Date::Date()
{
}
// 三個輸入參數建構子實作
Date::Date(int newMonth, int newDay, int newYear)
{
    month = newMonth;
    day = newDay;
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
// 設定年實作
void Date::setYear(int newYear)
{
    year = newYear;
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
// 取得年實作
int Date::getYear() const
{
    return year;
}
// StuCard 類別
class StuCard
{
public:
    // 預設建構子
    StuCard();
    // 四個輸入參數建構子
    StuCard(string, bool, double[3], Date);
    // 設定名字
    void setName(string);
    // 設定性別
    void setSex(bool);
    // 設定分數
    void setScore(int, double);
    // 設定生日
    void setDate(Date);
    // 取得名字
    string getName();
    // 取得性別
    bool getSex();
    // 取得分數
    double getScore(int);
    // 取得生日
    Date getDate();
    // 計算平均成績
    double average();
    // 取得今年年齡
    int getAge(int);
    // 輸出函式
    void printCard();

private:
    // 資料欄位(data fields) 為 private，分別有姓名、性別、成績陣列、生日
    string name;
    bool sex;
    double scoreAry[3];
    Date birthday;
};
// 預設建構子實作
StuCard::StuCard()
{
}
// 四個輸入參數建構子實作
StuCard::StuCard(string newName, bool newSex, double newScoreAry[3], Date newBirthday)
{
    name = newName;
    sex = newSex;
    birthday = newBirthday;
    for (int i = 0; i < 3; i++)
        scoreAry[i] = newScoreAry[i];
}
// 設定名字實作
void StuCard::setName(string newName)
{
    name = newName;
}
// 設定性別實作
void StuCard::setSex(bool newSex)
{
    sex = newSex;
}
// 設定分數實作
void StuCard::setScore(int newIndex, double newScore)
{
    scoreAry[newIndex] = newScore;
}
// 設定生日實作
void StuCard::setDate(Date newBirthday)
{
    birthday = newBirthday;
}
// 取得名字實作
string StuCard::getName()
{
    return name;
}
// 取得性別實作
bool StuCard::getSex()
{
    return sex;
}
// 取得分數實作
double StuCard::getScore(int newIndex)
{
    return scoreAry[newIndex];
}
// 取得生日實作
Date StuCard::getDate()
{
    return birthday;
}
// 計算平均成績實作
double StuCard::average()
{
    double total = 0;
    for (int i = 0; i < 3; i++)
        total += scoreAry[i];
    return total / 3;
}
// 取得今年年齡實作
int StuCard::getAge(int thisYear)
{
    return thisYear - birthday.getYear();
}
// 輸出函式實作
void StuCard::printCard()
{
    cout << getName() << ", " << getSex() << ", " << setprecision(1) << fixed << getScore(0) << ", " << getScore(1)
         << ", " << getScore(2) << ", " << getDate().getMonth() << "/" << getDate().getDay() << "/"
         << getDate().getYear() << ", " << average() << ", " << getAge(2020) << endl;
}
// 計算各科班平均
double *classAver(StuCard addScore[3], int size)
{
    double static exArr[3] = {0};
    for (int i = 0; i < size; i++)
        exArr[i] = addScore[i].getScore(i) / 5;
    return exArr;
}
// 主程式
int main()
{
    // 宣告四個學生
    double score1[3] = {80.0, 70.0, 90.0};
    StuCard s1("Jerry", 1, score1, Date(3, 20, 1997));

    double score2[3] = {85.0, 77.0, 95.0};
    StuCard s2("John", 1, score2, Date(5, 20, 1995));

    double score3[3] = {83.0, 75.0, 70.0};
    StuCard s3("Mary", 0, score3, Date(2, 18, 2007));

    double score4[3] = {73.0, 95.0, 67.0};
    StuCard s4("Tom", 1, score4, Date(11, 8, 2003));

    // 宣告欲輸入的五個變數、一個陣列，分別為姓名、性別、年、月、日、成績陣列
    string name;
    bool sex;
    double score[3];
    int month, day, year;

    // 輸入
    cin >> name >> sex >> score[0] >> score[1] >> score[2] >> month >> day >> year;

    // 根據輸入值建立第五個學生
    double score5[3] = {score[0], score[1], score[2]};
    StuCard s5(name, sex, score5, Date(month, day, year));

    // 將五個學生依序輸出
    s1.printCard();
    s2.printCard();
    s3.printCard();
    s4.printCard();
    s5.printCard();

    // 將成績分別存入三個陣列
    StuCard addScore[3];
    addScore[0].setScore(0, score1[0] + score2[0] + score3[0] + score4[0] + score5[0]);
    addScore[1].setScore(1, score1[1] + score2[1] + score3[1] + score4[1] + score5[1]);
    addScore[2].setScore(2, score1[2] + score2[2] + score3[2] + score4[2] + score5[2]);

    // 輸出班平均
    double *avg = classAver(addScore, 3);
    cout << "Average: " << *avg << ", " << *(avg + 1) << ", " << *(avg + 2) << endl;

    return 0;
}