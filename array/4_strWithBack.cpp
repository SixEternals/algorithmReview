//
/*
844. 比较含退格的字符串
给定 s 和 t 两个字符串，当它们分别被输入到空白的文本编辑器后，如果两者相等，返回 true 。# 代表退格字符。
注意：如果对空文本输入退格字符，文本继续为空。

示例 1：
输入：s = "ab#c", t = "ad#c"
输出：true
解释：s 和 t 都会变成 "ac"。

示例 2：
输入：s = "ab##", t = "c#d#"
输出：true
解释：s 和 t 都会变成 ""。

示例 3：
输入：s = "a#c", t = "b"
输出：false
解释：s 会变成 "c"，但 t 仍然是 "b"。


提示：
1 <= s.length, t.length <= 200
s 和 t 只含有小写字母以及字符 '#'

进阶：
你可以用 O(n) 的时间复杂度和 O(1) 的空间复杂度解决该问题吗？
*/
/*
1
s = "ab#c#", t = "ad#c"
     f            s f
"a b # c" -> "a b # c" -> ""

s = "aaaaaaa####bb#" -> "aaab"
              f
"aaaaaaa####bb#"
             fs                 fs
"aaaaaaa####bb#" -> "aaaaaaa####b##" arr[f] = arr[s--]
           fs                 f s
"aaaaaaa####b##" -> "aaaaaaa#######"
...
       f    s
"aaaaaaa#######"

       f           fs          fs
"aaa##b#" -> "aaa##b#" -> "aaa####"
   f s         f  s
"aaa####" -> "aa#####" -> "a######"


str = "ab#c" if(str[f] != '#') str[f]=str[++slow]
    f        f         fs        fs       f s
"ab#c" -> "ab#c" -> "ab#c" -> "abcc" -> "abcc"


str = "ab##c"  str[f] = str[f+1]
     f         f        f s       f s        f s
"ab##c" -> "ab##c" -> "ab##c" -> "a###c" -> "####c" -> done!

str = "abccc###bbccc####"
                 f                 f   s               f   s                 f    s
"abccc###bbccc####" ->"abccc###bbccc####" -> "abccc###b########" -> "abccc###b########"
重置s
         f                    fs                   f  s                 f  s
"abccc###b########" -> "abccc###b########" -> "abccc###b########" -> "ab######b########" -> abb

比较操作后的s和t字符串 比如"ab######b########" 和 "a#####b#c###"
 i                      j
"ab######b########" 和 "a#####b#c###"
  i                           j
"ab######b########" 和 "a#####b#c###"
if(s[i] == '#') ++i;
if(t[j] == '#') ++j;
if(s[i] != s[j]) return false;



             f       f      f s
ab##a -> ab##a -> ab##a -> ab##a -> ab##a
如果没碰到# 则f-- s--
从后往前遍历 如果碰到# 则slow不可以--
直到碰到第一个非'#' 就开始消除
然后重置slow的位置
int slow = size() - 1;
for(int fast = size() - 1; fast >= 0; --fast){
    if(str[fast] != '#')
        s --;
    if(str[fast] == '#')
    {
        while(str[fast] == '#') fast --;
        int pos2stop = fast;
        while(slow != pos2stop)
        {
            str[fast] = str[slow];
            slow--;
            fast --;
        }
        slow = fast;
    }
}
ac#d#
*/
// 从后往前便利？ 实际位置是slow指针所指位置
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        return analyze(s) == analyze(t);
    }
    string analyze(string &str)
    {
        /*
         f             f          sf          sf         s  f
        "ab##c#" -> "AB##c#" -> "AB##c#" -> "A###c#" -> "A###c#" -> "####c#"
         s   f       s    f
     -> "####c#" -> "c###c#" ->
        */
        int slow = 0;
        for (int fast = 0; fast < str.size(); ++fast)
        {
            if (str[fast] != '#')
                str[slow++] = str[fast];
            else
            {
                if (slow > 0)
                    slow--;
            }
        }
        return str.substr(0, slow);
    }
};
int main(int argc, char const *argv[])
{
    Solution instance;
    string str = "a#cccccccccc", t = "b";
    cout << instance.backspaceCompare(str, t);
    return 0;
}
