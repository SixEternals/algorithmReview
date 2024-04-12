// https://leetcode.cn/problems/combinations/description/
/*
77. 组合
给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
你可以按 任何顺序 返回答案。

示例 1：
输入：n = 4, k = 2
输出：
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

示例 2：
输入：n = 1, k = 1
输出：[[1]]

提示：
1 <= n <= 20
1 <= k <= n
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> res;               // 存放符合条件结果的集合
    vector<int> path;                      // 存放符合条件的结果
    void dfs(int n, int k, int startIndex) // 第三个参数相当于y总模板的u
    {
        if (path.size() == k)
        {
            res.emplace_back(path);
            return;
        }
        for (int i = startIndex; i <= n; ++i)
        {
            path.emplace_back(i);
            dfs(n, k, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) // 左闭右闭
    {
        res.clear();
        path.clear();
        dfs(n, k, 1);
        return res;
    }
    void func(int n, int k, int startIndex)
    { // 剪枝优化
        // 举例 n=4 k=4 那么只有[1,2,3,4]了 for循环从2 3 4开始枚举根本没有意义 因为长度都凑不齐k==4
        if (path.size() == k)
        {
            res.emplace_back(path);
            return;
        }
        // for (int i = startIndex; i <= startIndex + k && i <= n; ++i) 注意不能这样写 完全搞错了剪枝在减什么
        for (int i = startIndex; i <= n - (k - path.size()) + 1; ++i)
        {
            path.emplace_back(i);
            dfs(n, k, i + 1);
            path.pop_back();
        }
    }
};
int main(int argc, char const *argv[])
{
    Solution instance;
    auto res = instance.combine(4, 2);
    return 0;
}
