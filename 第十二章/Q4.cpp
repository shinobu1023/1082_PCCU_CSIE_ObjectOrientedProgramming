/*==========================================

第四題-成績vector

==========================================*/

#include <iostream>
#include <iomanip>
#include <vector> // 將會使用到 vector
using namespace std;

// 計算學生平均
double stuAve(vector<double> newScoreArray)
{
    // 宣告一個總和值
    double total = 0;
    // 用迴圈將每人分數加總
    for (int i = 0; i < newScoreArray.size(); i++)
        total += newScoreArray[i];
    // 回傳平均值
    return total / newScoreArray.size();
}

// 計算每科平均
double *courseAve(vector<vector<double>> newCourseArray)
{
    // 宣告一個儲存各科平均的陣列
    double static finAve[3] = {0};
    // 將每人的各科分別加總
    for (int i = 0; i < newCourseArray.size(); i++)
    {
        finAve[0] += newCourseArray[i][0];
        finAve[1] += newCourseArray[i][1];
        finAve[2] += newCourseArray[i][2];
    }
    // 將各科平均
    finAve[0] /= newCourseArray.size();
    finAve[1] /= newCourseArray.size();
    finAve[2] /= newCourseArray.size();
    // 回傳各科平均的陣列
    return finAve;
}
// 主程式
int main()
{
    // 根據題目建立二維陣列
    double exScoreArray[5][3] = {
        {80.0, 70.0, 90.0},
        {85.0, 77.0, 95.0},
        {83.0, 75.0, 70.0},
        {73.0, 95.0, 67.0},
        {88.0, 79.0, 71.0}};
    // 宣告一個 5*3 的二維 vector
    vector<vector<double>> score(5);
    for (int i = 0; i < score.size(); i++)
    {
        score[i] = vector<double>(3);
    }
    // 將二維陣列中每個值放入二維 vector 中
    for (int i = 0; i < score.size(); i++)
    {
        for (int j = 0; j < score[i].size(); j++)
        {
            score[i][j] = exScoreArray[i][j];
        }
    }
    // 印出二維陣列中每個值並在最後印出每個人平均分數
    for (int i = 0; i < score.size(); i++)
    {
        for (int j = 0; j < score[i].size(); j++)
        {
            cout << setprecision(1) << fixed << score[i][j] << ", ";
        }
        cout << stuAve(score[i]) << endl;
    }
    // 印出各科平均
    double *course = courseAve(score);
    cout << "Average: " << *(course) << ", " << *(course + 1) << ", " << *(course + 2) << endl;

    return 0;
}