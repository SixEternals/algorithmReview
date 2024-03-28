/*
小明对数位中含有2、0、1、9 的数字很感兴趣（不包括前导0）
在1到40中这样的数包括1、2、9、10 至32、39 和40，共28 个，他们的和是574。
请问，在1到n 中，所有这样的数的和是多少？
40 -- 574
*/
#include <iostream>
#include <vector>
using namespace std;
int n;
using LL = long long;
LL sum = 0;
void func(int x)
{
    int tmp = x;
    while (tmp != 0)
    {
        if (tmp % 10 == 1 || tmp % 10 == 2 || tmp % 10 == 9 || tmp % 10 == 0)
        {
            sum += x;
            break;
        }
        tmp /= 10;
    }
}
int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        func(i);
    }

    cout << sum << endl;

    return 0;
}
