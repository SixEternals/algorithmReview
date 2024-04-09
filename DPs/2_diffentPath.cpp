// https://leetcode.cn/problems/unique-paths/description/

/*

4 不同路径 Ⅰ
题目描述：
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

问总共有多少条不同的路径？
实例 1：
输入：m = 3, n = 7
输出：28
示例 2：

输入：m = 2, n = 3
输出：3

*/
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int dp[105][105];
    int uniquePaths(int m, int n)
    { // 这个是我自己写出来的ac代码 力扣里用时3ms 优化版为下面的optimal
        // dp
        if (m == 1 && n == 1)
            return 1;
        // init
        dp[1][1] = 1;
        dp[2][1] = dp[1][2] = 1;
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
            {
                if ((i == 1 && j == 1) || (i == 2 && j == 1) || (i == 1 && j == 2))
                    continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        return dp[m][n];
    }
    int dfsVersion(int i, int j, int m, int n)
    { // 时间复杂度爆了
        if (i > m || j > n)
            return 0;
        // exit
        if (i == m && j == n)
            return 1;
        return dfsVersion(i + 1, j, m, n) + dfsVersion(i, j + 1, m, n);
    }
    int optimal(int m, int n)
    { // 优化思路 把一行和一列分别初始化
        if (m == 1 && n == 1)
            return 1;
        // init  可以省掉m * n格时间
        for (int i = 1; i <= m; ++i)
            dp[i][1] = 1;
        for (int i = 1; i <= n; ++i)
            dp[1][i] = 1;
        //... 后面和上面一样
    }

    // 教你怎么使用vector
    int op2(int m, int n)
    {
        vector<vector<int>> dp2(m, vector<int>(n, 0));
        // ... 其他地方和你写出来的ac代码一样
    }
    // 优化为一维滚动数组
    int op3(int m, int n)
    {
        vector<int> dp3(n); // 存列长度
        for (int i = 0; i < n; ++i)
            dp3[i] = 1;
        for (int j = 1; j < m; ++j)
            for (int i = 1; i < n; ++i)
                dp3[i] += dp3[i - 1];
        return dp3[n - 1];
    }
    // 还有个数论版本不搬了
};

int main(int argc, char const *argv[])
{
    Solution instance;
    auto res = instance.uniquePaths(3, 7);
    cout << res << endl;
    return 0;
}
