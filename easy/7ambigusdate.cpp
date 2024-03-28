/*
http://oj.ecustacm.cn/problem.php?id=1328
小明正在整理一批历史文献。这些历史文献中出现了很多日期。
小明知道这些日期都在1960年1月1日至2059年12月31日。
令小明头疼的是，这些日期采用的格式非常不统一，有采用年/月/日的，有采用月/日/年的，还有采用日/月/年的。
更加麻烦的是，年份也都省略了前两位，使得文献上的一个日期，存在很多可能的日期与其对应。
比如02/03/04，可能是2002年03月04日、2004年02月03日或2004年03月02日。
给出一个文献上的日期，你能帮助小明判断有哪些可能的日期对其对应吗？
输入格式
一个日期，格式是"AA/BB/CC"。  (0 <= A, B, C <= 9)
输出格式
输出若干个不相同的日期，每个日期一行，格式是"yyyy-MM-dd"。
多个日期按从早到晚排列。

输入样例
02/03/04
输出样例
2002-03-04
2004-02-03
2004-03-02
*/

#include <iostream>
#include <vector>
using namespace std;

int isLeapYear(int year)
{
    // 判断闰年的逻辑是正确的，无需更改
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ? 1 : 0;
}

// 检查日期是否合法的函数，无需更改
bool isValidDate(int year, int month, int day)
{
    // 每个月的天数数组，2月根据是否闰年进行调整
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(year))
    {
        daysInMonth[1] = 29;
    }
    return year >= 1960 && year <= 2059 && month >= 1 && month <= 12 && day >= 1 && day <= daysInMonth[month - 1];
}

// 主函数
int main()
{
    int aa, bb, cc;
    scanf("%d/%d/%d", &aa, &bb, &cc); // 输入格式正确，无需更改

    // 枚举所有可能的年份，从1960年到2059年
    for (int year = 1960; year <= 2059; ++year)
    {
        // 枚举所有可能的月份
        for (int month = 1; month <= 12; ++month)
        {
            // 枚举所有可能的日期
            for (int day = 1; day <= 31; ++day)
            { 
                if (isValidDate(year, month, day))
                {
                    if (aa == year % 100 && bb == month && cc == day)
                    {
                        printf("%04d-%02d-%02d\n", year, month, day); // 格式化输出日期
                    }
                    // 检查当前日期是否与输入的日期相匹配（年和日交换）
                    if (aa == month && bb == year % 100 && cc == day)
                    {
                        printf("%04d-%02d-%02d\n", year, month, day); // 格式化输出日期
                    }
                    // 检查当前日期是否与输入的日期相匹配（月和日交换）
                    if (aa == day && bb == year % 100 && cc == month)
                    {
                        printf("%04d-%02d-%02d\n", year, month, day); // 格式化输出日期
                    }
                }
            }
        }
    }
    return 0;
}
/*
哦哦 原来是题目说了只需要判断三类情况年月日 月日年 日月年

AA/BB/CC
年月日
年日月
月年日
月日年
日年月
日月年
*/
