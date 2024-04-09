// https://leetcode.cn/problems/unique-binary-search-trees/description/

/*
96. 不同的二叉搜索树
给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。
示例 1：
输入：n = 3
输出：5
示例 2：
输入：n = 1
输出：1

提示：1 <= n <= 19
*/
/*
二叉树特点：左小右大
所以代码随想录的例子里的编号不是自上而下的由小到大哦
假如只有三个节点 则排列和编号如下
      3     3      1        1          2
    /      /        \        \        / \
   2      1          2        3      1   3
  /        \          \      /
 1          2          3    2

要注意的点是 空二叉树也是树  ∴dp[0]=1
dp[1]=1 而dp[2]也是可以推导的 dp[2]=2

推导过程：
左子树的所有排列x右子树的所有排列
说明为什么是乘法而不是加法：因为排列组合
我们枚举j 从1枚举到n 意味着当我们有j个元素时 有多少二叉树排列
对于j j的左子树小于j 故左子树有j-1个元素（根据二叉树的定义 左小右大）
j的右子树节点数为i-j
看上图 if j == 3 左边必定有3-1=2个节点 因为3比1 2都大
       if j == 1 左边没有节点 因为编号为1的节点是最小编号 没有比它更小的
递推公式：dp[i] = dp[j-1] * dp[i-j] (记得这里是乘法)

init: dp[0] = 1,dp[1] = 1

*/
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> dp(n + 1, 0);
        // init
        dp[0] = 1; // be CAREFUL!!! 别初始化dp[1]=1
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= i; ++j)
                dp[i] += dp[j - 1] * dp[i - j];

        // print
        for (int i = 1; i <= n; ++i)
            cout << dp[i] << " ";
        puts("");
        return dp[n];
    }
};
int main(int argc, char const *argv[])
{
    Solution instance;
    cout << instance.numTrees(3);
    return 0;
}
