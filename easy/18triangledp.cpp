#include <iostream>
using namespace std;
int g[510][510], dp[510][510];
int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N); // 层数
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= i; ++j)
            scanf("%d", &g[i][j]);

    // 初始化dp的最底层
    for (int i = 1; i <= N; ++i)

        dp[N][i] = g[N][i];

    // 自底向上遍历
    for (int i = N - 1; i >= 1; --i)
        for (int j = 1; j <= i; ++j)
        {
            // int l = g[i + 1][j] + dp[i][j] + g[i][j];
            // int r = g[i + 1][j + 1] + dp[i][j] + g[i][j];
            // dp[i][j] = max(l, r);
            dp[i][j] = max(dp[i + 1][j] + g[i][j], dp[i + 1][j + 1] + g[i][j]);
            // 解释：g存图 dp存的是集合的最大值dp[i+1][j]相当于从底层到当前点'的'左下点的最大权值
            // 同理dp[i+1][j+1]相当于从底层到当前点的右下角点的最大权值 这左右两部分取最大
            // g[i][j]代表当前点的权值 dp[i+1][j]相当于

            // 假设当前点是A 则g[i][j]就是当前点A的权值 dp[i+1][j]就是从最底层到点B的权值最大的路径
            /*
               A
              B C
             D E F
            G H I J

            */

            // 第一步优化 把+g[i][j]提取出来
            // dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + g[i][j];

            // 第二部优化 上面式子可以进一步把权值g给优化掉 直接使用dp存入图 因为是自底向上更新所以可以直接覆盖掉
            // dp[i][j] += max(dp[i+1][j],dp[i+1][j+1])
        }
    cout << dp[N][N];
    return 0;
}
