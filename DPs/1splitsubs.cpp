// https://leetcode.cn/problems/partition-equal-subset-sum/description/
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        // get sum of nums;
        int total = 0;
        for (auto n : nums)
            total += n;
        if (total % 2 != 0)
            return false; // 整数相加不可能为小数
        // fill dp
        int W = total / 2; // 相当于背包承重
        vector<int> dp(W + 1, 0);
        dp[0] = 1; //  dp[i]表示 和为i 的组合种数
        for (auto num : nums)
            for (int i = W; i >= num; --i)
                dp[i] += dp[i - num];

        // check
        for (int i = 0; i <= W; ++i)
            cout << "dp[" << i << "] = " << dp[i] << " ";

        return dp[W] != 0; // 由于int溢出 所以不能写dp[W] > 0
    }
};
int main()
{
    vector<int> nums{10, 10, 10, 10, 2};
    Solution instance;
    auto flag = instance.canPartition(nums);
    cout << endl
         << flag << endl;
    return 0;
}

/*
二维做法
https://blog.csdn.net/qq_37206105/article/details/89288763
*/

// 1 2 10 3 4
/* 假设[1,2,10,3,4]   ->   [1,2,3,4] and [10]
1 num=1 for(i=10;i>=1;--i) dp[10] += dp[9]
...........................dp[1] += dp[0],dp[1] = 1
2 num=2 for(i=10;i>=2;--i) dp[10] += dp[8]
...........................dp[2] += dp[1]+dp[0] , dp[2] = 2
3 num=3 for(i=10;i>=3;--i) dp[10] += dp[7]
...........................dp[3] += dp[0]+dp[1]+dp[2] , dp[3] = 4

计算sum及target = sum / 2

检查奇偶性：sum为奇数 -> 不可能分割成两个整数子集

初始化
*/

/*
416. 分割等和子集

给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

示例 1：
输入：nums = [1,5,11,5]
输出：true
解释：数组可以分割成 [1, 5, 5] 和 [11] 。

示例 2：
输入：nums = [1,2,3,5]
输出：false
解释：数组不能分割成两个元素和相等的子集。

提示：
1 <= nums.length <= 200
1 <= nums[i] <= 100
*/
