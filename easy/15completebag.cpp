#include <iostream>
using namespace std;
// dp[][] w[] v[] N V
int N, V;
const int Size = 1010;
int dp[Size][Size];
int w[Size], v[Size];
int main(int argc, char const *argv[])
{
    scanf("%d %d", &N, &V); // 物品数量 背包容积
    for (int i = 1; i <= N; ++i)
        scanf("%d %d", &w[i], &v[i]); // 体积 价值

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= V; ++j)
            for (int k = 0; k * w[i] <= j; ++k) // 这里不能写k <= V / v[i]
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * w[i]] + k * v[i]);
                // cout << dp[i][j] << " ";
            }
    cout << dp[N][V];

    // cout << "\ncheck" << endl;
    // for (int i = 1; i <= N; ++i, puts(""))
    //     for (int j = 1; j <= V; ++j)
    //         printf("%d ", dp[i][j]);
    return 0;
}
/*
最佳搭配
4+4+2 = 10
*/
