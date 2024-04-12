// https://leetcode.cn/problems/spiral-matrix-ii/description/
/*
59. 螺旋矩阵 II
给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。

示例 1：
输入：n = 3
输出：[[1,2,3],[8,9,4],[7,6,5]]

示例 2：
输入：n = 1
输出：[[1]]

提示：
1 <= n <= 20
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> res(n, vector<int>(n));
        int startx = 0, starty = 0;
        int loop = n / 2, mid = n / 2;
        int count = 1;
        int offset = 1;
        int i, j;
        while (loop--)
        {
            i = startx, j = starty;
            for (j; j < n - offset; ++j)
                res[i][j] = count++;
            for (i; i < n - offset; ++i)
                res[i][j] = count++;
            for (j; j > starty; --j)
                res[i][j] = count++;
            for (i; i > startx; --i)
                res[i][j] = count++;
            // increment
            startx++, starty++, offset++;
        }
        if (n % 2 == 1)
            res[mid][mid] = n * n;
        return res;
    }
};
int main(int argc, char const *argv[])
{
    int n = 3;
    Solution instance;
    vector<vector<int>> res = instance.generateMatrix(n);

    return 0;
}
