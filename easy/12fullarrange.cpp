// https://leetcode.cn/problems/permutations/description/
#include <iostream>
#include <vector>
using namespace std;

// class Solution
// {
// public:
//     vector<int> a;           // 用于记录每次排列
//     vector<vector<int>> ans; // 记录所有排列
//     vector<bool> visited;    // 用于记录元素是否被访问过

//     void DFS(int u, const vector<int> &nums)
//     {
//         if (u == nums.size())
//         {
//             ans.push_back(a); // 添加当前排列到结果中
//             return;
//         }

//         for (int i = 0; i < nums.size(); ++i)
//         {
//             if (!visited[i])
//             {                         // 如果元素未被访问
//                 visited[i] = true;    // 标记为已访问
//                 a.push_back(nums[i]); // 添加元素到当前排列
//                 DFS(u + 1, nums);     // 递归处理下一个位置
//                 a.pop_back();         // 回溯，移除最后一个元素
//                 visited[i] = false;   // 取消标记
//             }
//         }
//     }

//     vector<vector<int>> permute(vector<int> &nums)
//     {
//         visited.resize(nums.size()); // 初始化访问状态数组
//         DFS(0, nums);                // 开始递归
//         return ans;
//     }
// };
class Solution
{
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int> &nums)
    {
        int n = nums.size();
        recur(nums, n, 0);
        return res;
    }
    void recur(vector<int> &nums, int n, int loc)
    {
        if (loc == n)
        {
            res.push_back(nums);
            return;
        }
        for (int i = loc; i < n; i++)
        {
            swap(nums[i], nums[loc]);
            recur(nums, n, loc + 1);
            swap(nums[i], nums[loc]);
        }
        return;
    }
};
int main()
{
    Solution instance;
    vector<int> arr{1, 2, 3};
    auto res = instance.permute(arr);
    // 打印所有全排列
    for (const auto &perm : res)
    {
        for (int num : perm)
        {
            printf("%d ", num);
        }
        printf("\n");
    }
    return 0;
}