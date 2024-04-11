// https://leetcode.cn/problems/move-zeroes/description/
/*
283. 移动零
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
请注意 ，必须在不复制数组的情况下原地对数组进行操作。

示例 1:
输入: nums = [0,1,0,3,12]
输出: [1,3,12,0,0]

示例 2:
输入: nums = [0]
输出: [0]

提示:
1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
*/

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int slow{0};
        int len = nums.size();
        for (int fast = 0; fast < len; ++fast)
            if (nums[fast] != 0)
                nums[slow++] = nums[fast];
        for (int i = slow; i < len; ++i)
            nums[i] = 0;
    }
};
/*
 s f
[0,1,0,3,1,2]
   s f
[1,1,0,3,1,2]
   s   f
[1,1,0,3,1,2]
     s   f
[1,3,0,3,1,2]
       s
[1,3,1,2,.,.]
then init zero
for(i=s+1,i < len) arr[i]=0
return s+1
*/
int main(int argc, char const *argv[])
{
    vector<int> nums{0, 1, 0, 3, 1, 2}; // [1,3,1,2,0,0];
    Solution instance;
    instance.moveZeroes(nums);
    return 0;
}
