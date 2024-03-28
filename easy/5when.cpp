// http://oj.ecustacm.cn/problem.php?id=1368
/*
2000年的1月1日，是那一年的第1天。
那么，2000年的5月4日，是那一年的第几天？
*/
#include <iostream>
using namespace std;
int months1[12]{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int months2[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool isRun(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return true;
    return false;
}
int main(int argc, char const *argv[])
{
    int year = 2000, month = 1, day = 1;
    int year1 = 2000, month1 = 5, day1 = 4;

    int days = 0;
    if (isRun(year))
    {
        // months1
        for (int i = 0; i < month1 - 1; i++)
        {
            days += months1[i];
        }
        days += day1;
    }
    else
    {
        for (int i = 0; i < month1 - 1; i++)
        {
            days += months2[i];
        }
        days += day1;
    }
    cout << days << endl;
    return 0;
}
