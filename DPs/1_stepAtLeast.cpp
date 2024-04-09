#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        vector<int> dp(cost.size() + 1, 0);
        // init
        dp[0] = dp[1] = 0;
        // evaluation dp[i]=min(dp[i-1]+cost[i-1], dp[i-2] + cost[i-2])
        // 顺序是？ 从前往后--可行√
        for (int i = 2; i <= cost.size(); ++i)
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        return dp[cost.size()];
    }
    int sub(vector<int> &cost)
    { // 优化版 类似于fib中只需要三个数字迭代
        int left = 0, right = 0, size = cost.size();
        for (int i = 2; i <= size; ++i)
        {
            int tmp = min(left + cost[i - 1], right + cost[i - 2]);
            right = left;
            left = tmp;
        }
    }
};
int main(int argc, char const *argv[])
{
    Solution instance;
    vector<int> cost{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << instance.minCostClimbingStairs(cost);
    return 0;
}
/*
746. 使用最小花费爬楼梯
给一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。
你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。
请你计算并返回达到楼梯顶部的最低花费。

示例 1：
输入：cost = [10,15,20]
输出：15
解释：你将从下标为 1 的台阶开始。
- 支付 15 ，向上爬两个台阶，到达楼梯顶部。
总花费为 15 。

示例 2：      0  1  2 3 4  5  6 7  8  9
输入：cost = [1,100,1,1,1,100,1,1,100,1]
输出：6
解释：你将从下标为 0 的台阶开始。
- 支付 1 ，向上爬两个台阶，到达下标为 2 的台阶。
- 支付 1 ，向上爬两个台阶，到达下标为 4 的台阶。
- 支付 1 ，向上爬两个台阶，到达下标为 6 的台阶。
- 支付 1 ，向上爬一个台阶，到达下标为 7 的台阶。
- 支付 1 ，向上爬两个台阶，到达下标为 9 的台阶。
- 支付 1 ，向上爬一个台阶，到达楼梯顶部。
总花费为 6 。
*/