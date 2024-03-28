#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
int question[10][10]{}, rowmark[10][10]{}, colmark[10][10]{}, blockmark[10][10]{};
int row[10]{}, col[10]{}, block[10]{};
clock_t start, finish;
struct point
{
    int r, c, n = 0;
    point(int _r, int _c) : r(_r), c(_c) {}
};
vector<point> tofill;
void setmark(int r, int c, int n, bool flag) { rowmark[r][n] = colmark[c][n] = blockmark[getblocknum(r, c)][n] = flag; }
inline int getblocknum(int r, int c) { return ((r - 1) / 3) * 3 + ((c - 1) / 3); }
bool judge(int r, int c, int n) { return !rowmark[r][n] && !colmark[c][n] && !blockmark[getblocknum(r, c)][n]; }
bool dfs(int);
void printboard();
void Clear();
int main(int argc, const char *argv[])
{
    start = clock();
    int count;
    cin >> count;
    while (count--)
    {
        for (int r = 1; r < 10; r++)     // from 1 to 9
            for (int c = 1; c < 10; c++) // from 1 to 9
            {
                char ch;
                cin >> ch;
                question[r][c] = ch - '0';
                if (question[r][c] == 0)
                    tofill.push_back(point(r, c));
                else
                    setmark(r, c, question[r][c], 1);
            }
        if (dfs(0))
            printboard();
        Clear();
    }
    finish = clock();
    // cout<<(finish-start)<<endl;
    return 0;
}
void printboard()
{
    for (int r = 1; r < 10; r++, puts("")) // from 1 to 9
        for (int c = 1; c < 10; c++)       // from 1 to 9
            cout << question[r][c];
}
void Clear()
{
    for (int i = 0; i <= 10; i++)
        for (int j = 0; j <= 10; j++)
            rowmark[i][j] = colmark[i][j] = blockmark[i][j] = question[i][j] = 0;
}
bool dfs(int step)
{
    if (step == tofill.size())
        return true;
    int reverse = (int)tofill.size() - step - 1;
    int r = tofill[reverse].r, c = tofill[reverse].c;
    for (int i = 1; i < 10; i++)
        if (judge(r, c, i))
        {
            question[r][c] = i;
            setmark(r, c, question[r][c], 1);
            if (dfs(step + 1))
                return true;
            setmark(r, c, question[r][c], 0);
            question[r][c] = 0;
        }
    return false;
}