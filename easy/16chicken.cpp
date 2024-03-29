/*
5
1 2 2 3 1  b[]
1 2 3 3 1  a[]
调整： 找到a最大b最小的
find MaxA & MinB → 3(2) 3(3) 1(1) 1(1) 2(2)
*/
#include <iostream>
using namespace std;
const int N = 46;
int dp[N], nums;
int a[N], b[N];
const int INF = 0x3f3f3f3f;
int main(int argc, char const *argv[])
{
    scanf("%d", &nums);
    for (int i = 1; i <= nums; ++i)
        scanf("%d", &b[i]);
    for (int i = 1; i <= nums; ++i)
        scanf("%d", &a[i]);
    int MaxA = 0;
    for (int i = 1; i <= nums; ++i)
        for (int j = nums; j >= b[i]; --j)
        {
            dp[j] = max(dp[j], dp[j - b[i]] + a[i]);
            MaxA = max(MaxA, dp[j]);
        }

    cout << dp[nums];
    return 0;
}
/*
5
1 2 2 3 1
1 2 3 3 1
*/
