// https://leetcode.cn/problems/integer-break/
/*
343. 整数拆分
给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。
返回 你可以获得的最大乘积 。
示例 1:
输入: n = 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1。

示例 2:
输入: n = 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。

提示:2 <= n <= 58
*/

/*
动规五部曲
1 确定dp数组及其下标含义：当正整数为i时 其拆分组合的最大积为dp[i]
2 确定递推公式 dp[i] = max(dp[i], j*dp[i-j])
3 dp初始化 dp[0]=dp[1]=0 dp[2] = 1
4 确定遍历顺序： 从小到大(正序)
5 举例推导dp数组(检验)

属性为cnt

拆分举例 说明为啥是 j * dp[i-j]
i=1时 1+0  ->dp[1]=1*0=0
i=2   1+1//2+0   ->dp[2]=1*1=1
i=3   1+2//1+1+1//3+0   -> dp[3] = 2   其中1+2可以把后面的2拆出成1+1 即可以把2的结果从dp[2]中取出来
因为dp[2]已经是最大乘积了
..
i=5   1+1+1+1+1//1+2+2//3+2//4+1//5+0  -> dp[5] = 6
i=6   1+1+1+1+1+1//2+4//1+5....   ->  先拆1+5得(1x1)x(1x1x1x1x1)一共六个1 再拆2+4得2x(1x1x1x1) 这里不用拆2是因为再拆就和(1+5)的组合一模一样了  所以递推公式才是j*dp[i-j]而不是dp[j]*dp[i-j] 因为从小到大遍历j的话 dp[j]的拆分情况早就被涵盖了

数学证明
本问题即求x^(a-x)的极值 其中x相当于j a相当于i
(图像早忘了思密达) 当x=e时最大 即2.7...... 就是说当拆成若干个3的近似值整数后能得到最大
比如说i=100 可拆
50x50 = 2500
33x33x34 = 37026
25x25x25x25 = 390625
20x20x20x20x20 = 3million
...
总之就是越来越大 枚举到3就算了 懒
3^(100-3) = 1.9^46
*/

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int integerBreak(int n)
    {
        vector<int> dp(n + 1, 0);
        // init
        dp[0] = dp[1] = 0;
        dp[2] = 1;
        // evaluation: dp[i] = max(dp[i] ,j * dp[i-j])
        for (int i = 3; i <= n; ++i)
            for (int j = 1; j <= i / 2 + 1; ++j) // 枚举到i的一半就可以了
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
        // dp[i] = max(dp[i], j * dp[i - j]);
        // print
        // for (int i = 1; i <= n; ++i)
        //     cout
        //         << dp[i] << " ";
        return dp[n];
    }
};
int main(int argc, char const *argv[])
{
    Solution instance;
    cout << endl
         << instance.integerBreak(3) << endl;
    return 0;
}
