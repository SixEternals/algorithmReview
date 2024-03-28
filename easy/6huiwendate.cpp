/*
在日常生活中，通过年、月、日这三个要素可以表示出一个唯一确定的日期。
牛牛习惯用 8 位数字表示一个日期，其中，前 4 位代表年份，接下来 2 位代表月份，最后 2 位代表日期。

显然：一个日期只有一种表示方法，而两个不同的日期的表示方法不会相同。

牛牛认为，一个日期是回文的，当且仅当表示这个日期的8位数字是回文的。

现在，牛牛想知道：在他指定的两个日期之间（包含这两个日期本身），有多少个真实存在的日期是回文的。

一个 8 位数字是回文的，当且仅当对于所有的 i(1≤i≤8) 从左向右数的第i个数字和第 9−i 个数字（即从右向左数的第 i 个数字）是相同的。

例如：

•对于2016年11月19日，用 8 位数字 20161119 表示，它不是回文的。

•对于2010年1月2日，用 8 位数字 20100102 表示，它是回文的。

•对于2010年10月2日，用 8 位数字 20101002 表示，它不是回文的。
原文链接：https://blog.csdn.net/Mr_Ghost812/article/details/104220234
*/
#include <iostream>
using namespace std;
using LL = long long;
LL cnt = 0;
void split(int &y, int &m, int &d, int date)
{
    int tmp = date;
    int unit, ten; // 个位 十位
    unit = tmp % 10;
    tmp /= 10;
    ten = tmp % 10;
    tmp /= 10;
    d = unit + ten * 10;

    unit = tmp % 10;
    tmp /= 10;
    ten = tmp % 10;
    tmp /= 10;
    m = unit + ten * 10;

    y = tmp % 10;
    tmp /= 10;
    y += (tmp % 10) * 10;
    tmp /= 10;
    y += (tmp % 10) * 100;
    tmp /= 10;
    y += (tmp % 10) * 1000;
}

void func(int dat1, int dat2)
{
    int y1, y2, m1, m2, d1, d2;
    split(y1, m1, d1, dat1);
    split(y2, m2, d2, dat2);
}

bool func2(int y, int m, int d)
{
    int yearfront = (y / 100);
    int yearrear = (y % 100);

    // reverse month and day
    int monthR = (m % 10) * 10;
    monthR += m / 10;
    int dayR = (d % 10) * 10;
    dayR += d / 10;
    if (monthR == yearrear && dayR == yearfront)
        return true;
    return false;
}
int isRun(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1;
    return 0;
}
int main(int argc, char const *argv[])
{
    // cout << func2(2012, 21, 2);

    int dat1 = 20110101, dat2 = 20111231;
    cin >> dat1 >> dat2;
    // func(dat1, dat2);

    // int a, b, c;
    // split(a, b, c, 20241030);
    // cout << a << " " << b << " " << c << endl;
    int year1 = dat1 / 10000;
    int month1 = (dat1 / 100) % 100;
    int day1 = dat1 % 100;
    int year2 = dat2 / 10000;
    int month2 = (dat2 / 100) % 100;
    int day2 = dat2 % 100;

    int MONTHS[12]{31, 28 + isRun(year1), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (int y = year1; y <= year2; y++)
    {
        MONTHS[1] = 28 + isRun(y);
        for (int m = 1; m <= 12; ++m)
        {
            // 跳过起始之日和终止之日之后的日子
            if (y == year1 && m < month1)
                continue;
            if (y == year2 && m > month2)
                continue;

            int currentmonth = MONTHS[m - 1];
            for (int d = 1; d <= currentmonth; ++d)
            {
                if (func2(y, m, d))
                    cnt++;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}

// 样例1
// 20000104
// 29991221
// 输出36

// 样例2
// 15200101
// 20771230
// 输出 10