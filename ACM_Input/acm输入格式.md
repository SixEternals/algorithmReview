[ACM](
ACM 输入输出模板下载: https://pan.baidu.com/s/1R35L0C5nRzM4ykhFJr_B6w?pwd=rpuo)
[本地地址](<../卡码网ACM模板/卡码网-ACM输入输出模板(C++,Java,Python,go,JS).pdf>)

# C++输入

string 部分
（其中 getline 是位于`#include <string>头文件里`）
`scanf("%s", &str);` -> 遇到制表符/空格/换行符就停止录入
`cin >> str;` -> 同上一条
`getline(str, cin);` -> 遇到换行符`\n`才会停止

我的建议是 while 里面不要用 scanf 了 用 `cin`
例如`多组数据,每组第⼀⾏为 n,之后输⼊ n ⾏两个整数`
`若⼲⾏输⼊，每⾏输⼊两个整数，遇到特定条件终⽌`
`若干行输入，遇到0终止，每行第一个数为N，表示本行后面有N个数`
