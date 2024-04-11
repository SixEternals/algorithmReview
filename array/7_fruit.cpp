// https://leetcode.cn/problems/fruit-into-baskets/description/
/*
904. 水果成篮
你正在探访一家农场，农场从左到右种植了一排果树。这些树用一个整数数组 fruits 表示，其中 fruits[i] 是第 i 棵树上的水果 种类 。
你想要尽可能多地收集水果。然而，农场的主人设定了一些严格的规矩，你必须按照要求采摘水果：
你只有 两个 篮子，并且每个篮子只能装 单一类型 的水果。每个篮子能够装的水果总量没有限制。
你可以选择任意一棵树开始采摘，你必须从 每棵 树（包括开始采摘的树）上 恰好摘一个水果 。采摘的水果应当符合篮子中的水果类型。每采摘一次，你将会向右移动到下一棵树，并继续采摘。
一旦你走到某棵树前，但水果不符合篮子的水果类型，那么就必须停止采摘。
给你一个整数数组 fruits ，返回你可以收集的水果的 最大 数目。

示例 1：
输入：fruits = [1,2,1]
输出：3
解释：可以采摘全部 3 棵树。

示例 2：
输入：fruits = [0,1,2,2]
输出：3
解释：可以采摘 [1,2,2] 这三棵树。
如果从第一棵树开始采摘，则只能采摘 [0,1] 这两棵树。

示例 3：
输入：fruits = [1,2,3,2,2]
输出：4
解释：可以采摘 [2,3,2,2] 这四棵树。
如果从第一棵树开始采摘，则只能采摘 [1,2] 这两棵树。

示例 4：
输入：fruits = [3,3,3,1,2,1,1,2,3,3,4]
输出：5
解释：可以采摘 [1,2,1,1,2] 这五棵树。

提示：
1 <= fruits.length <= 105
0 <= fruits[i] < fruits.length
*/

/*
好若只的机翻 唉这就是我们中国力扣分部吗 堂堂一个中等题能给我翻译出“哥特式金属私生子”和“老头滚动条”的美
言简意赅就是滑动窗口里只能有两种数字 比如说[2,2,2,3,3,2,2,2,2]里面只有2和3

从实例2可以看出来只可以是连续的

可以用哈希+滑动窗口
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        unordered_map<int, int> cnt;
        int fast = 0, slow = 0;
        int ans = 0;
        for (int i = 0, j = 0; i < fruits.size(); ++i)
        {
            int x = fruits[i];
            ++cnt[x];
            while (cnt.size() > 2)
            {
                int y = fruits[j++];
                if (--cnt[y] == 0)
                    cnt.erase(y);
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    Solution instance;
    vector<int> fruits{3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    cout << instance.totalFruit(fruits);
    return 0;
}
