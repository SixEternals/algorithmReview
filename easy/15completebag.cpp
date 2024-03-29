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
            for (int k = 0; k * w[i] <= j; ++k) // 这里不能写k <= V / v[i] 过了两小时之后的吐嘈：这不废话吗 v是价值啊 看来是坐在水客教室里焖傻了
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * w[i]] + k * v[i]);

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
/**
 解释
 在动态规划中，"完美背包"问题和"0/1背包"问题的解决方案之所以采用不同的遍历顺序，是因为这两个问题的特性和约束条件不同。

### 完美背包问题（Perfect Knapsack Problem）：
- 物品可以选取多件。
- 每个物品的重量和价值都是正整数。
- 目标是选择物品使得总重量不超过背包容量，且总价值最大。

在完美背包问题中，通常采用**正向遍历**的方式，因为物品可以选择多件，所以每个物品都有可能在最优解中出现，不论其重量大小。正向遍历确保了每个物品都被考虑到，并且可以被重复选择，从而找到总价值最大的组合。

### 0/1背包问题（0/1 Knapsack Problem）：
- 每个物品只能选取一件。
- 每个物品的重量和价值都是正整数。
- 目标是选择物品使得总重量不超过背包容量，且总价值最大。

在0/1背包问题中，通常采用**反向遍历**的方式，因为每个物品只能选择一次。反向遍历的优势在于，当背包容量较大时，较大的物品价值更有可能在解中出现。通过从后向前遍历物品，我们可以优先考虑价值较高的物品，这样可以更快地填满背包容量，并且更容易找到最优解。

### 为什么遍历顺序不同？
- 在完美背包问题中，由于可以多次选择同一个物品，所以物品的选择不受其重量大小的限制。正向遍历可以确保所有可能的选择都被考虑到，从而找到最优解。
- 在0/1背包问题中，由于每个物品只能选择一次，所以较大的物品更有可能对最终解产生影响。反向遍历可以帮助我们更快地排除那些不可能进入最优解的小物品，从而减少搜索空间，提高求解效率。

总结来说，遍历顺序的选择是为了适应不同背包问题的特性和约束条件，以及为了提高求解效率。在实际编程实现中，根据问题的特性选择合适的遍历顺序是非常重要的。

*/