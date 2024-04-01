// https://www.acwing.com/problem/content/897/
#include <iostream>
using namespace std;

int f[1010], dp[1010];
int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
        scanf("%d", &f[i]);

    for (int i = 1; i <= N; ++i)
    {
        dp[i] = 1;
        for (int j = 1; j < i; ++j)
            if (f[j] < f[i])
            {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
    }
    int res = 0;
    for (int i = 1; i <= N; ++i)
        res = max(res, dp[i]);
    cout << res << endl;
    return 0;
}
/*
时间复杂度O(n^2)
第一次写时的易错点
① 第二层循环别忘了 要从头遍历比i小的数字
② 是if (f[j] < f[i]) 而不是j<i 又犯老毛病了唉唉
③ 记得取max 虽然写的时候记得这个啦
④ 忘记找出dp数组里面的最大了 注意不是dp[N]最大
*/