/*==========================================

第十三章-循序檔

==========================================*/

#include <iostream>
#include <iomanip> // 將會使用到 setprecision
#include <string>  // 將會使用到 string
#include <fstream> // 將會使用到 ifstream 與 ofstream
using namespace std;

// StuCard 類別
class StuCard
{
public:
    // 建構子
    StuCard(string, bool, double[3]);
    // 設定名字
    void setName(string);
    // 設定性別
    void setSex(bool);
    // 設定分數
    void setScore(double newScoreAry[3]);
    // 取得名字
    string getName();
    // 取得性別
    bool getSex();
    // 設定某一科分數
    double getScore(int);
    // 寫入檔案
    void writeToFile(ofstream &);
    // 讀取檔案
    void readFromFile(ifstream &);

private:
    // 資料欄位(data fields) 為 private，分別有姓名、性別、分數陣列(存三科分數)
    string name;
    bool sex;
    double scoreAry[3];
};
// 建構子實作
StuCard::StuCard(string newName, bool newSex, double newScoreAry[3]) : name(newName), sex(newSex)
{
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
void StuCard::setScore(double newScoreAry[3])
{
    for (int i = 0; i < 3; i++)
        scoreAry[i] = newScoreAry[i];
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
// 設定某一科分數實作
double StuCard::getScore(int newIndex)
{
    return scoreAry[newIndex];
}
// 寫入檔案實作
void StuCard::writeToFile(ofstream &out)
{
    out << name << " " << sex << " " << fixed << setprecision(1) << scoreAry[0] << " " << scoreAry[1] << " " << scoreAry[2] << endl;
}
// 讀取檔案實作
void StuCard::readFromFile(ifstream &in)
{
    string z;
    bool x;
    double c[3];
    in >> z >> x >> c[0] >> c[1] >> c[2];
    cout << fixed << setprecision(1) << z << " " << x << " " << c[0] << " " << c[1] << " " << c[2] << endl;
}
// 主程式
int main()
{
    // 建立一個 ofstream，並利用此進行開檔，準備進行寫入檔案(以附加方式)
    ofstream out;
    out.open("StuCard.txt", ios::out | ios::app);

    // 建立五個物件，並一一寫入檔案
    double Score_1[3] = {80.0, 70.0, 90.0};
    StuCard s1("Jerry", 1, Score_1);

    s1.writeToFile(out);

    double Score_2[3] = {85.0, 77.0, 95.0};
    StuCard s2("John", 1, Score_2);

    s2.writeToFile(out);

    double Score_3[3] = {83.0, 75.0, 70.0};
    StuCard s3("Mary", 0, Score_3);

    s3.writeToFile(out);

    double Score_4[3] = {73.0, 95.0, 67.0};
    StuCard s4("Tom", 1, Score_4);

    s4.writeToFile(out);

    double Score_5[3] = {88.0, 79.0, 71.0};
    StuCard s5("Claire", 0, Score_5);

    s5.writeToFile(out);

    // 關閉檔案
    out.close();

    // 建立一個 ifstream，並利用此進行開檔，準備進行讀取檔案
    ifstream in;
    in.open("StuCard.txt", ios::in);

    // 讀取檔案
    StuCard s6[5] = {s1, s2, s3, s4, s5};
    for (int i = 0; i < 5; i++)
    {
        s6[i].readFromFile(in);
    }

    // 關閉檔案
    in.close();

    return 0;
}