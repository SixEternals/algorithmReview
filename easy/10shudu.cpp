#include <iostream>
using namespace std;
const int N = 16;
const int Size = 5;
int n = 16, a[N];
// bool st[N]; 以下三个数组就是st状态数组的实例化
bool rows[Size][5], cols[Size][5], blocks[Size][5];
int getBlock(int row, int col)
{
    if ((row >= 1 && row <= 2) && (col >= 1 && col <= 2))
        return 1;
    if ((row >= 1 && row <= 2) && (col >= 3 && col <= 4))
        return 2;
    if ((row >= 3 && row <= 4) && (col >= 1 && col <= 2))
        return 3;
    if ((row >= 3 && row <= 4) && (col >= 3 && col <= 4))
        return 4;
    return 0;
}
int ans = 0;
void dfs(int u)
{
    if (u > n)
    {
        // for (int i = 1; i <= n; ++i)
        // {
        //     printf("%d ", a[i]);
        //     if (i % 4 == 0)
        //         puts("");
        // }
        ans++;
        return;
    }
    int row = (u - 1) / 4 + 1, col = (u - 1) % 4 + 1;
    // int block = getBlock(row, col);
    int block = (row - 1) / 2 * 2 + (col - 1) / 2 + 1;
    for (int i = 1; i <= 4; ++i) // 这里只能是4 因为只有1 2 3 4这四个数字可以填
    {
        if (!rows[i][row] && !cols[i][col] && !blocks[i][block])
        {
            rows[i][row] = cols[i][col] = blocks[i][block] = true;
            a[u] = i;
            dfs(u + 1);
            rows[i][row] = cols[i][col] = blocks[i][block] = false;
        }
    }
}
int main(int argc, char const *argv[])
{
    dfs(1);
    cout << ans;
    return 0;
}
