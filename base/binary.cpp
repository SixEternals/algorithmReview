#include <iostream>
using namespace std;
int n, q, k;
int a[100010];
int SL(int l, int r, int x)
{
    while (l < r)
    {
        int mid = l + r >> 1; // 注意这里把mid放进循环里！！！
        if (a[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}
int SR(int l, int r, int x)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (a[mid] <= x)
            l = mid + 1;
        else
            r = mid;
    }
    return r;
}
int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    while (q--)
    {
        scanf("%d", &k);
        int l = SL(0, n, k);
        if (a[l] != k)
            cout << "-1 -1" << endl;
        else
            cout << l << " " << SR(0, n, k) - 1 << endl;
    }
}