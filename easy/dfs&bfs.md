[原文链接](https://blog.csdn.net/GD_ONE/article/details/104189342)

dfs 模板

```cpp
int n,N = 10;
int a[N];
bool st[N];
void dfs(int u){
    if(u == n){
        // other operations...
        return ;
    }
    for(int i = 0 ; i < n ; ++i){
        if(st[i]) continue;
        st[i] = true;
        a[u] = i;
        dfs(u + 1);
        st[i] = false;
    }
}
dfs(0);
```

```cpp
#include <iostream>
using namespace std;
// 先复习四阶数独
/*
dfs格式
void dfs(int u){
    if(u > n) return;
    for(int i = 0; i < n ; ++i){

    }
}
                                 尤其注意n是要操作的个数 比如四阶数独要填入四种数字1 2 3 4 所以枚举范围是4 而由于16个格子都要填满所以退出条件是16
                                 而n皇后 当n=4, 枚举范围是4 因为只能填4个皇后，而因为一共只能填4个名额 那返回条件就是4了
                                 而填字游戏版的数独 和前面一样 要操作1-9的数字(总不能往里面填进30啥的吧) 然后退出条件做出了优化 只需要x大于空白格的数量即可
1
                                 所以dfs的要点就是要确定操作数是多少 以及退出条件
*/
const int Size = 5;
// st
bool b1[Size][5], b2[Size][5], b3[Size][5];
// record
int n = 4 * 4;
int arr[16];
int ans = 0;
void dfs(int u)
{
    if (u > n)
    {
        ans++;
        return;
    }
    int row = (u - 1) / 4 + 1, col = (u - 1) % 4 + 1;
    int block = (row - 1) / 2 * 2 + (col - 1) / 2 + 1;
    for (int i = 1; i <= 4; ++i)
    {
        if (!b1[row][i] && !b2[col][i] && !b3[block][i])
        {
            b1[row][i] = b2[block][i] = b3[col][i] = true;
            arr[u] = i;
            dfs(u + 1);
            b1[row][i] = b2[block][i] = b3[col][i] = false;
        }
    }
}
int main(int argc, char const *argv[])
{
    dfs(1); // 哦对了这代码是错的 我比对了半天也不知道哪里错了 总之10shudu.cpp是完全正确的
    cout << ans << endl;
    return 0;
}

```

```cpp
// 复习了一天之后 隔天再重写的N皇后 恭喜 一遍过
// 题目参照的是acwing的八皇后 要求输入二维char数组
#include <iostream>
using namespace std;
// 8Queue
// st arr N
int n;
const int N = 15;
bool col[N], row[N], dg[N], udg[N];
char a[N][N];
int ans;
void dfs(int u)
{
    if (u == n)
    {
        // print
        for (int i = 0; i < n; ++i)
            puts(a[i]);
        puts("");
        ++ans;
        return;
    }

    int &x = u;
    for (int y = 0; y < n; ++y) // 8皇后思路稍微不同一点 因为知道每一行就放一个 所以直接枚举列就行
    {
        if (!dg[y - x + n] && !udg[y + x] && !col[y]) // 连row的判断都省了 n皇后 很神奇吧
        {
            dg[y - x + n] = udg[y + x] = col[y] = true;
            a[x][y] = 'Q';
            dfs(u + 1);
            a[x][y] = '.';
            dg[y - x + n] = udg[y + x] = col[y] = false;
        }
    }
}
int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            a[i][j] = '.';
        }

    dfs(0); // 先试着写0 成功之后再改1
    cout << "ans = " << ans << endl;
    return 0;
}


```

_要注意，数独规则是行列和 nxn 子块上不得重复，而 N 皇后是行列和对角线反对角线都不能重复，两者判断条件不要混淆了_

# 纯做题环节

1.[力扣 46 全排列](https://leetcode.cn/problems/permutations/submissions/516843049/)
普通做法[](./12fullarrange.cpp)
进阶做法 ↓

```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        recur(nums, n, 0);
        return res;
    }
    void recur(vector<int>& nums, int n, int loc){
        if(loc==n){
            res.push_back(nums);
            return;
        }
        for(int i=loc;i<n;i++){
            swap(nums[i], nums[loc]);
            recur(nums, n, loc+1);
            swap(nums[i], nums[loc]);
        }
        return;
    }
};
```

## 优点

不需要标记 st 数组和没有产生额外空间消耗
loc 为递归深度 每一轮递归时 交换下标为 loc 及之后的元素
当 loc 触底时说明处理到数组的最后一个位置了 此时是一个合法的输入

## 不需要 st 数组标记的原因

∵`for(int i=loc;i < n; i++)` loc 是递归深度 当 loc 越来越大时 下标为 loc 之前的数字相当于固定了
则遵循一个规则：随着 loc 递增 把后面的全交换了

```cpp
[1,2,3] -- [1,3,2]
        \- [2,1,3]--[2,3,1]
       \-- [3,2,1]--[3,1,2]
```

2.[力扣 784. 字母大小写全排列](https://leetcode.cn/problems/letter-case-permutation/description/)
[普通做法](./13letterarrange.cpp)

```cpp
void dfs(int u, int n, string &s)
    {
        if (u == n)
        {
            ans.emplace_back(s);
            return;
        }
        dfs(u + 1, n, s); // 注意看 这里先递归到字符串尾了
        if (s[u] >= 'A' && s[u] <= 'Z')
        {
            s[u] += 32;
            dfs(u + 1, n, s);
        }
        else if (s[u] >= 'a' && s[u] <= 'z')
        {
            s[u] -= 32;
            dfs(u + 1, n, s);
        }
    }
```

解释：看[图解](./11pictures/dfs回溯树.jpg)
只要做好复原的准备 即使不是模板的 for 样子也行 这题就用了两 if 语句来复原 同时避开了数字
