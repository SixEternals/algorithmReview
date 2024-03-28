#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> ans;
    void dfs(int u, int n, string &s)
    {
        if (u == n)
        {
            ans.emplace_back(s);
            return;
        }
        dfs(u + 1, n, s);
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
    vector<string> letterCasePermutation(string s)
    {
        dfs(0, s.size(), s);
        return ans;
    }
};
// 这样吧 逆转思维 直接只记录字母的位置然后对其直接dfs
int main(int argc, char const *argv[])
{
    // printf("%d %d", 'a', 'A'); // a97 A65
    Solution instance;
    string s{"a1b2"};
    auto ans = instance.letterCasePermutation(s);
    cout << "s = " << s << endl;
    for (auto i : ans)
        cout << i << " " << endl;
    return 0;
}
