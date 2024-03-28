#include <iostream>
using namespace std;
const int N = 11;
int arr[N];
bool st[N];
int n;
void dfs(int u)
{
    if (u == n)
    {
        for (int i = 0; i < n; ++i)
            cout << arr[i] << " ";
        puts("");
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (st[i])
            continue;
        st[i] = true;
        arr[u] = i;
        dfs(u + 1);
        st[i] = false;
    }
}
int main(int argc, char const *argv[])
{
    // 这里犯了一个很傻的错误：n重定义 定义了个全局n又定义了个局部Int n;
    cin >> n;
    dfs(0);
    return 0;
}
