// https://leetcode.cn/problems/minimum-size-subarray-sum/description/
/*
209. 长度最小的子数组
给定一个含有 n 个正整数的数组和一个正整数 target 。
找出该数组中满足其总和大于等于 target 的长度最小的 连续
子数组[numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

示例 1：
输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。

示例 2：
输入：target = 4, nums = [1,4,4]
输出：1

示例 3：
输入：target = 11, nums = [1,1,1,1,1,1,1,1]
输出：0

提示：
1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 105
*/
/*
先排序[2,3,1,2,4,3]
->    [1,2,2,3,3,4]
滑动窗口
 f                s f                s   f              s     f
[1,2,2,3,3,4] -> [1,2,2,3,3,4] 3 -> [1,2,2,3,3,4] 5 -> [1,2,2,3,3,4] 8
   s   f              s     f
[1,2,2,3,3,4] 6 -> [1,2,2,3,3,4]

前缀和
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int slow = 0;
        for (int fast = 0; fast < nums.size(); ++fast)
        {
        }
    }
};
int main(int argc, char const *argv[])
{
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    Solution instance;
    instance.minSubArrayLen(7, nums);
    return 0;
}
