// 二维背包
// #include <iostream>
// using namespace std;
// // dp复习
// int N, V; // 物品数量， 容积
// const int Size = 1e3 + 10;
// int w[Size], v[Size];
// int dp[Size][Size];
// int main(int argc, char const *argv[])
// {
//     scanf("%d %d", &N, &V);
//     for (int i = 1; i <= N; ++i)
//         scanf("%d %d", &w[i], &v[i]); // 体积w 价值v

//     for (int i = 1; i <= N; ++i)
//         for (int j = 1; j <= V; ++j)
//             if (j >= w[i])
//                 dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
//             else
//                 dp[i][j] = dp[i - 1][j];
//     cout << dp[N][V];
//     return 0;
// }

// 一维背包 第二层循环需要倒叙来保证读到的前驱数据是旧的
// #include <iostream>
// using namespace std;
// const int Size = 1e3 + 10;
// int N, V;
// int w[Size], v[Size];
// int dp[Size];
// int main(int argc, char const *argv[])
// {
//     scanf("%d %d", &N, &V); // 物品数量 背包容积
//     for (int i = 1; i <= N; ++i)
//         scanf("%d %d", &w[i], &v[i]); // 体积w 价值v

//     for (int i = 1; i <= N; ++i)
//         for (int j = V; j >= w[i]; --j)
//             dp[j] = max(dp[j], dp[j - w[i]] + v[i]); // 这句我理解了√

//     cout << dp[V]; //  输出背包容量为 V 时的最大价值。这是因为 dp[V] 存储了在背包容量限制 V 下能获得的最大价值，这是通过动态规划算法计算得出的最终结果。
//     return 0;
// }

// 终极优化
#include <iostream>
using namespace std;
int N, V;
int dp[1010];
int main(int argc, char const *argv[])
{
    int w, v;               // weight value
    scanf("%d %d", &N, &V); // 物品数量 背包容积
    for (int i = 1; i <= N; ++i)
    {
        scanf("%d %d", &w, &v); // 体积 价值
        for (int j = V; j >= w; --j)
            dp[j] = max(dp[j], dp[j - w] + v);
    }
    cout << dp[V];
    return 0;
}
