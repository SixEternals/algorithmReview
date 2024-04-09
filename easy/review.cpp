// 用朴素解法来做的话 时间复杂度是O(n^2) 若数据量上万了就会容易OT
/* 优化思路写道了dp笔记里了 */
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int n, a[N], q[N];
int len; // 记录当前已知的最长子序列的长度
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    // init 讲a[0]添加到q中 此时len=1
    q[1] = a[0];
    len = 1;

    // 下标为q数组服务 然后循环n-1次
    for (int i = 1; i < n; ++i)
    {
        // 二分查找
        int l = 0, r = len;
        // 按照模板 寻找一个数 它的下一个数是a[i]
        while (l < r)
        {

            int mid = l + r + 1 >> 1; // 防止向下溢出
            if (q[mid] < a[i])
                l = mid;
            else
                r = mid - 1;
        }
        // 更新len
        len = max(len, r + 1);
        // 更新q 将a[i]添加到正确的为止
        q[r + 1] = a[i];
    }
    cout << len;
    return 0;
}
/*
详细解释
1 init
a数组存原始数据
q数组存储结尾元素 其下标表示子序列的长度 数组元素对于长度的最小结尾元素
len用于记录当前已知的最长子序列的长度

2初始化q和len 用途如上

好处：只需要输出len 避免了枚举所有有可能的子序列
而是通过维护一个有序数组q来快速找到每个元素的最佳插入位置
从O(n^2)降到O(nlogn)
*/

/*
详细解释
q[]下标就表示字串长度 即q[1]表示递增字串长度为1的元素为xx
a[]存储输入数据

因为前面已经初始化了q[1]=a[0]和len=1 所以相当于已经访问了q[1]和a[0]了
故写for (int i = 1; i < n; ++i) 下标从1开始 遍历q 循环n-1次(已经访问了一个了) 再a的访问不能超过n

至于mid为什么这样写？使用边界分析法——画图
画图判断q[mid]与a[i]的大于 等于 小于的关系 从而判断l = mid + ?和r = mid + ?

至于mid要不要+1怎么判断？
直接预算一遍：当l=0,r=1时 若使用mid = 0 + 1 >> 1则会得到mid=0 由于我们是针对q的遍历
所以Mid=0就是犯规的 要+1弥补一下
*/