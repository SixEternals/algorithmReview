#include <iostream>
#include <vector>
using namespace std;
/*
题型一 数字分割(每年必出)
数字分割出各个位数

例如：给你一个数字486，把它的各个位数分割出来，然后做一些操作
*/
void func(int num)
{
    int x = num;
    vector<int> tmp;
    while (x != 0)
    {
        tmp.push_back(x % 10);
        x /= 10;
    }
    for (auto i = tmp.rbegin(); i != tmp.rend(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
}
int main(int argc, char const *argv[])
{
    vector<int> arr{1, 100, 99, 101};

    for (int i = 0; i < arr.size(); ++i)
        func(arr.at(i));

    return 0;
}
