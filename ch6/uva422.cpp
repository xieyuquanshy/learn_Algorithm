/* uva422
 * 2020/11/22
 */
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
const int M = 1e4 + 10;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-5;
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pb(x) push_back(x)
#define bg begin()
#define ed end()
#define mp make_pair
#define mem(x, a) memset(x, a, sizeof(x));
#define endl '\n'
#define _for(i, a, b) for (int i = a; i < b; ++i)
#define _rep(i, a, b) for (int i = a; i <= b; ++i)
#define Test

// 矩阵结构体
struct Martix {
    int row, col;  // 行、列
    Martix(int row = 0, int col = 0) : row(row), col(col) {}
} a[30];

int main() {
#ifdef Test
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n;
    scanf("%d", &n);
    _rep(i, 1, n) {
        string name;
        cin >> name;
        int k = name[0] - 'A';
        cin >> a[k].row >> a[k].col;  // 用矩阵的名字代替下标
    }
    string op;
    while (cin >> op) {
        int ans = 0;
        stack<Martix> s;
        bool ok = true;

        _for(i, 0, sz(op)) {
            if (isalpha(op[i]))  // 碰到字符入栈
                s.push(a[op[i] - 'A']);
            else if (op[i] == ')') {  // 碰到右括号出栈
                Martix m1 = s.top();
                s.pop();
                Martix m2 = s.top();
                s.pop();
                if (m2.col != m1.row) {  // 如果不符合矩阵相乘的条件
                    ok = false;
                    break;
                }
                ans += m2.row * m2.col * m1.col;  // 加上乘法次数
                s.push(Martix(m2.row, m1.col));   // 将相乘后的矩阵入栈
            }
        }
        if (!ok)
            printf("error\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}