/*==========================================

第一題-循序檔案

==========================================*/

#include <iostream>
#include <string>  // 將會運用到 string
#include <iomanip> // 將會運用到 setprecision
#include <fstream> // 將會運用到 fstream
using namespace std;

// Teacher 類別
class Teacher
{
public:
    // 預設建構子
    Teacher();
    // 帶有三個參數建構子 (名字、年齡、考績分數)
    Teacher(string, int, double);
    // 設定名字函式
    void setName(string);
    // 取得名字函式
    string getName();
    // 設定年齡函式
    void setAge(int);
    // 取得年齡函式
    int getAge();
    // 設定分數函式
    void setScore(double);
    // 取得名字函式
    double getScore();
    // 寫入檔案函式
    void writeToFile(ostream &out);
    // 讀取檔案函式
    void readFromFile(istream &in);

private:
    // 資料欄位(data fields) 為 private，分別有姓名、年齡、考績分數
    string name;
    int age;
    double score;
};
// 預設建構子實作
Teacher::Teacher()
{
}
// 帶有三個參數建構子實作
Teacher::Teacher(string newName, int newAge, double newScore)
{
    name = newName;
    age = newAge;
    score = newScore;
}
// 設定名字函式實作
void Teacher::setName(string newName)
{
    name = newName;
}
// 取得名字函式實作
string Teacher::getName()
{
    return name;
}
// 設定年齡函式實作
void Teacher::setAge(int newAge)
{
    age = newAge;
}
// 取得年齡函式實作
int Teacher::getAge()
{
    return age;
}
// 設定分數函式實作
void Teacher::setScore(double newScore)
{
    score = newScore;
}
// 取得名字函式實作
double Teacher::getScore()
{
    return score;
}
// 寫入檔案函式實作
void Teacher::writeToFile(ostream &out)
{
    out << fixed << setprecision(1) << name << " " << age << " " << score << endl;
}
// 讀取檔案函式實作
void Teacher::readFromFile(istream &in)
{
    string newName;
    int newAge;
    double newScore;
    in >> newName >> newAge >> newScore;
    cout << fixed << setprecision(1) << newName << " " << newAge << " " << newScore << endl;
}
// 主程式
int main()
{
    // 宣告一個物件陣列儲存4個物件
    Teacher t[4];

    // 利用迴圈輸入並建立物件
    for (int i = 0; i < 4; i++)
    {
        string name;
        int age;
        double score;
        cin >> name >> age >> score;
        t[i] = Teacher(name, age, score);
    }

    // 宣告一個 fstream，將會利用此進行開檔關檔
    fstream io;

    // 開 Teacher.txt 檔案 (並以輸出和附加方式)
    io.open("Teacher.txt", ios::out | ios::app);
    // 利用迴圈將物件資訊寫入檔案
    for (int i = 0; i < 4; i++)
        t[i].writeToFile(io);
    // 關檔
    io.close();

    // 開 Teacher.txt 檔案 (並以輸入方式)
    io.open("Teacher.txt", ios::in);
    // 利用迴圈將檔案內資訊讀取出來
    for (int i = 0; i < 4; i++)
        t[i].readFromFile(io);
    // 關檔
    io.close();

    return 0;
}