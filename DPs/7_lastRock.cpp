// https://leetcode.cn/problems/last-stone-weight-ii/description/
/*
1049. 最后一块石头的重量 II
有一堆石头，用整数数组 stones 表示。其中 stones[i] 表示第 i 块石头的重量。
每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：
如果 x == y，那么两块石头都会被完全粉碎；
如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
最后，最多只会剩下一块 石头。返回此石头 最小的可能重量 。如果没有石头剩下，就返回 0。

示例 1：
输入：stones = [2,7,4,1,8,1]
输出：1
解释：
组合 2 和 4，得到 2，所以数组转化为 [2,7,1,8,1]，
组合 7 和 8，得到 1，所以数组转化为 [2,1,1,1]，
组合 2 和 1，得到 1，所以数组转化为 [1,1,1]，
组合 1 和 1，得到 0，所以数组转化为 [1]，这就是最优值。

示例 2：
输入：stones = [31,26,33,21,40]
输出：5

提示：
1 <= stones.length <= 30
1 <= stones[i] <= 100
*/

/*
不好意思 瞄到了一眼攻略 规律为分成两拨重量相同/相近的石头堆相撞就得了
这不完全就是第六题吗

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {                           // 按照0ms的ac代码修改以下部分 标记为“新增i”
        if (stones.size() == 1) // 新增1
            return stones[0];
        int sum = 0;

        // 新增2 取出stones.size()
        auto m = stones.size();
        for (int i = 0; i < m; ++i)
            sum += stones[i];
        // 分成两堆相似的石头堆也行 就不用判断sum是不是奇数了
        // init
        int target = sum / 2;
        vector<int> dp(15001, 0); // 要记得这里长度不是stones.size()哦
        for (int i = 0; i < m; ++i)
            for (int j = target; j >= stones[i]; --j)
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
        return sum - 2 * dp[target];
    }
};
int main(int argc, char const *argv[])
{
    Solution instance;
    vector<int> stones{2, 7, 3, 1, 8, 1};
    cout << instance.lastStoneWeightII(stones);
    return 0;
}
