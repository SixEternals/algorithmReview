// 计算某年某日到现在一共多少天 要点：怎么算闰年
// 闰年标准

#include <iostream>
using namespace std;

bool isRun(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    return false;
}
int main(int argc, char const *argv[])
{
    cout << isRun(1900) << endl;
    return 0;
}
