// https://www.dotcpp.com/oj/problem2571.html
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int D[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 每个月的天数
bool checkLeapYear(int y)
{ // 判断闰年
    if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
        return true;
    return false;
}
bool checkABABBABAstyle(string s)
{ // 判断是否为ABABBABA型
    if (s[0] == s[2] && s[0] == s[5] && s[0] == s[7] && s[1] == s[3] && s[1] == s[4] && s[1] == s[6])
        return true;
    return false;
}
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        string S, ans1, ans2;
        string s, t, year;
        int y, m, d, i;
        cin >> S;
        year = S.substr(0, 4);
        for (i = stoi(year); ans1 == "" || ans2 == ""; i++)
        {
            // i 初值为输入数据的年
            //  找到了ans1和ans2，循环结束，有任何一个没有找到 就要继续循环寻找
            s = to_string(i), t = to_string(i); // s为当前枚举的年
            reverse(t.begin(), t.end());        // 求i的逆
            s += t;                             // 构造拼接出 s+s'  年月日
            if (s <= S)
                continue; // 构造出的s 小于起始日期，不计，
            // 用continue 直接进入下一轮循环，考察下一年，下面的语句不执行。
            y = stoi(s.substr(0, 4)), m = stoi(s.substr(4, 2)), d = stoi(s.substr(6, 2));
            // 从回文串中获得年月日：y、m、d。
            if (checkLeapYear(y))
                D[2] = 29; // 如果是闰年，2月的天数为29，
            if (m < 1 || m > 12)
                continue; // 如果月m不在1到12之间，就不是合法月份，
            // 然后进入下一轮循环。
            if (d < 1 || d > D[m])
                continue; // 如果d不在1到D[m]之间，就不是合法日期。
            if (ans1 == "")
                ans1 = s; // s是合法日期的回文串，记录在ans1中
            if (checkABABBABAstyle(s) && ans2 == "")
                ans2 = s; // s还符合ABABBABA型，记录在ans2中。
        }
        cout << ans1 << '\n'
             << ans2 << '\n';
    }
    return 0;
}
/* 2024-3-27重写写对了
#include <iostream>
using namespace std;
int isRun(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ? 1 : 0;
}
bool isValid(int year)
{
    int month = (year % 10) * 10;
    month += (year % 100) / 10;
    int day = ((year / 100) % 10) * 10;
    day += (year / 1000);
    int months[13]{-1, 31, 28 + isRun(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return year >= 1000 && year <= 8999 && month >= 1 && month <= 12 && day >= 1 && day <= months[month];
}
bool isABABBABA(int year)
{
    return year % 10 == (year / 100) % 10 && (year / 10) % 10 == (year / 1000);
}
int main(int argc, char const *argv[])
{
    int date;
    scanf("%d", &date);
    bool flag = false;
    for (int year = date / 10000 + 1; year <= 8999; ++year)
    {
        if (!isValid(year))
            continue;
        if (!flag)
        {
            flag = true;
            int month = (year % 10) * 10;
            month += (year % 100) / 10;
            int day = ((year / 100) % 10) * 10;
            day += (year / 1000);
            int res1 = year * 10000 + month * 100 + day;
            cout << res1 << endl;
        }
        if (flag && isABABBABA(year))
        {
            int month = (year % 10) * 10;
            month += (year % 100) / 10;
            int day = ((year / 100) % 10) * 10;
            day += (year / 1000);
            int res2 = year * 10000 + month * 100 + day;
            cout << res2 << endl;
            break;
        }
    }

    return 0;
}

*/