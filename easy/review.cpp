// 二分查找
/*
给定一个按照升序排列的长度为 n的整数数组，以及 q个查询。
对于每个查询，返回一个元素 k的起始位置和终止位置（位置从 0开始计数）。
如果数组中不存在该元素，则返回 -1 -1。
输入格式
第一行包含整数 n 和 q，表示数组长度和询问个数。
第二行包含 n 个整数（均在 1∼10000 范围内），表示完整数组。
接下来 q 行，每行包含一个整数 k，表示一个询问元素。
输出格式
共 q 行，每行包含两个整数，表示所求元素的起始位置和终止位置。
如果数组中不存在该元素，则返回 -1 -1。
数据范围
1≤n≤100000
1≤q≤10000
1≤k≤10000
输入样例：
6 3
1 2 2 3 3 4
3
4
5
输出样例：
3 4
5 5
-1 -1
*/
#include <iostream>
using namespace std;
const int N = 100010;
int arr[N];
int n, q, k;
int SL(int l, int r, int x)
{ // 找到第一个大于等于x的下标
    while (l < r)
    {
        int mid = l + r >> 1;
        if (arr[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}
int SR(int l, int r, int x)
{ // 找到第一个大于x的值 范围左闭右开
    while (l < r)
    {
        int mid = l + r >> 1;
        if (arr[mid] <= x)
            l = mid + 1;
        else
            r = mid;
    }
    return r;
}
int main(int argc, char const *argv[])
{
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    while (q--)
    {
        scanf("%d", &k);
        auto l = SL(0, n, k);
        if (arr[l] != k)
            cout << "-1 -1" << endl;
        else
            cout << l << " " << SR(0, n, k) - 1 << endl;
    }
    return 0;
}
