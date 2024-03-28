#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    string input = "3%g2%n##";
    // cin >> input;

    stack<string> st;
    string result = "";
    int count = 0;

    for (char ch : input)
    {
        if (isdigit(ch))
        {
            // 如果是数字，将其转换为整数并保存到count中
            count = count * 10 + (ch - '0');
        }
        else if (ch == '%')
        {
            // 遇到"%"，将栈顶的字符串重复count次，并添加到结果中
            string top = st.top();
            for (int i = 0; i < count; ++i)
            {
                result += top;
            }
            // 弹出栈顶元素
            st.pop();
        }
        else if (ch == '#')
        {
            // 遇到"#"，将结果字符串压入栈中
            st.push(result);
            // 重置结果字符串
            result = "";
        }
        else
        {
            // 其他字符直接添加到结果字符串中
            result += ch;
        }
    }

    cout << result << endl;
    return 0;
}