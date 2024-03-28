#include <iostream>
using namespace std;
#include <vector>

int MONTHS[13]{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool isRun(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}
void dateAdd(int &date)
{
    int year = date / 10000;
    int month = (date / 100) % 100;
    int day = date % 100;
    bool isrun = isRun(year);
    if (isrun)
        MONTHS[2] = 29;
    else
        MONTHS[2] = 28;

    day++;
    // 2月
    if (month == 2 && ((isrun && day > 29) || !isrun && day > 28))
    {
        day = 1;
        month++;
    }
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        if (day > 31)
        {
            day = 1;
            month++;
        }

    if (month == 4 || month == 6 || month == 9 || month == 11)
        if (day > 30)
        {
            day = 1;
            month++;
        }

    if (month > 12)
    {
        month = 1;
        year++;
    }

    date = day + month * 100 + year * 10000;
    // cout << year << " " << month << " " << day << " " << endl;
}
int check[8];

bool isHuiwen(int date)
{
    int tmp = date;
    int check[8];
    for (int i = 7; i >= 0; --i)
    {
        check[i] = tmp % 10;
        tmp /= 10;
    }
    for (int i = 0; i < 4; ++i)
    {
        if (check[i] != check[7 - i])
            return false;
    }
    return true;
}

// bool isABABBABA(int date)
// {
//     int tmp = date;
//     for (int i = 7; i >= 0; --i)
//     {
//         check[i] = tmp % 10;
//         tmp /= 10;
//     }
//     if (check[0] == check[7] && check[1] == check[6] && check[2] == check[5] && check[3] == check[4] && check[0] == check[2] && check[1] == check[3] && check[1] == check[4])
//         return true;
//     return false;
// }
int ababType[2][9]{{10100101, 20200202, 30300303, 40400404, 50500505, 60600606, 70700707, 80800808, 90900909},
                   {11111111, 21211212, 31311313, 41411414, 51511515, 6161616, 71711717, 81811818, 91911919}};
// 10000101 ≤ N ≤ 89991231
int isABABBABA(int date)
{
    int firstNumber = date / 10000000;
    // cout << firstNumber << " " << ababType[0][firstNumber - 1] << " " << ababType[1][firstNumber - 1] << endl;

    if (date < ababType[0][firstNumber - 1])
        return ababType[0][firstNumber - 1];
    else if (date >= ababType[0][firstNumber - 1] && date < ababType[1][firstNumber - 1])
    {
        return ababType[1][firstNumber - 1];
    }
    else if (date >= ababType[1][firstNumber - 1])
        return ababType[0][firstNumber];

    // cout << "this is not supported" << endl;
    return ababType[8][1];
}
bool isValid(int date)
{
    int year = date / 10000;
    int month = (date / 100) % 100;
    int day = date % 100;
    int yearrear = year % 10;
    yearrear = yearrear * 10 + (year / 10) % 10; // month reversed
    int yearfront = (year / 100) % 10;
    yearfront = yearfront * 10 + (year / 1000); // day reversed

    // cout << year << " " << yearfront << " " << yearrear << endl;
    // cout << year << " " << month << " " << day << endl;

    // 30
    if (yearrear == 4 || yearrear == 6 || yearrear == 9 || yearrear == 11)
        if (yearfront <= 30)
            return true;
    // 31
    if (yearrear == 1 || yearrear == 3 || yearrear == 5 || yearrear == 7 || yearrear == 8 || yearrear == 10 || yearrear == 12)
        if (yearfront <= 31)
            return true;
    // feb
    if (isRun(year) && yearrear == 2)
    {
        return yearfront <= 29;
    }
    else if (isRun(year) && yearrear == 2)
    {
        return yearfront <= 28;
    }
    return false;
}
int main()
{
    // cout << isValid(13211231);
    // cout << isABABBABA(99999999);
    // int tmp = 20130331;
    // dateAdd(tmp);
    // cout << isValid(92201030) << endl; // 难绷 这个数字居然既是闰年 倒过来也是合法的
    // cout << isABABBABA(31311313) << endl;
    // int date = 20200101;
    // for (int i = 0; i < 367; ++i)
    // {
    //     dateAdd(date);
    //     if ((i + 1) % 20 == 0)
    //         printf("\n");
    //     printf("%d ", date);
    // }

    // --------------------------------------
    int n;
    cin >> n;
    while (n--)
    {
        int date;
        cin >> date;
        int datecopy = date;
        bool ishuiwen = false;
        bool f1 = false; // 这里不加f1 f2的话 会导致ishuiwen多次判定导致第一个cout<<date打印多次
        dateAdd(date);
        while (1)
        {
            // 这里可以加特判 直接用日和月对称筛选掉一部分不合格数据
            if (!isValid(date))
            {
                dateAdd(date);
                continue;
            }

            ishuiwen = isHuiwen(date);
            if (ishuiwen && f1 == false)
            {
                cout << date << endl;
                f1 = true;
            }
            if (f1 == true)
            {
                cout << isABABBABA(datecopy) << endl;
                break;
            }
            // if (ishuiwen && isababbaba)
            //     break;
            dateAdd(date);
        }
        // 记得重置
        ishuiwen = false;
    }
    return 0;
}
/*

1
20770101

20800802
30300303

对哦 那么ababbaba是不是本来就很少
就只有10100101 20200202 30300303 40400404 ....90900909 就九个数字
而且注意看 范围早就给死了
对于所有评测用例，10000101 ≤ N ≤ 89991231，保证N 是一个合法日期的8 位数表示
int ababType[8]{10100101,20200202,30300303,40400404,50500505,60600606,70700707,80800808,90900909}
{11111111,21211212,31311313,41411414,51511515,6161616,71711717,81811818,91911919}
{12122121,22222222,32322323,42422424,52522525......这一行都没用}
{13133131,23233232,33333333,43433434.....}
{14144141...}
{15155151...}
{16166161...}
{17177171...}
{18188181...}
{19199191...}
*/