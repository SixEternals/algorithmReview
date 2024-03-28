// http://oj.ecustacm.cn/problem.php?id=1508

/*
小蓝要为一条街的住户制作门牌号。
这条街一共有2020 位住户，门牌号从1 到2020 编号。
小蓝制作门牌的方法是先制作0 到9 这几个数字字符，最后根据需要将字符粘贴到门牌上，例如门牌1017 需要依次粘贴字符1、0、1、7，即需要1 个字符0，2 个字符1，1 个字符7。
请问要制作所有的1 到2020 号门牌，总共需要多少个字符2？
*/
#include <iostream>
#include <vector>
using namespace std;
vector<int> arr;
using LL = long long;
LL cnt = 0;
void func()
{
    for (auto i : arr)
    {
        // get each number
        int x = i;
        while (x != 0)
        {
            if (x % 10 == 2)
                cnt++;
            x /= 10;
        }
    }
}
int main(int argc, char const *argv[])
{
    for (int i = 1; i <= 2020; ++i)
    {
        arr.emplace_back(i);
    }
    func();
    cout << cnt << endl;

    return 0;
}
