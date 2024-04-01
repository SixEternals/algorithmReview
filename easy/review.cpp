// 复习线性dp 三角形
/*
关键 存图(权值)g[][]  状态值(题目要求max)dp[][]
*/
#include <iostream>
using namespace std;
int g[510][510], dp[510][510];
int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    // 存图
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= i; ++j)
            scanf("%d", &g[i][j]);

    // init dp
    for (int i = 1; i <= N; ++i)
        dp[N][i] = g[N][i];

    for (int i = N - 1; i; --i) // 由于从dp最底层向上而且dp最底层已经初始化了 而且这个两层循环里涉及到do[i+1]的操作 所以这里要i=N-1
        for (int j = 1; j <= i; ++j)
        {
            dp[i][j] = max(dp[i + 1][j] + g[i][j], dp[i + 1][j + 1] + g[i][j]);
        }
    cout << dp[1][1];
    return 0;
}
