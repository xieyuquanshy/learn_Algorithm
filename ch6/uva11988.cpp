/* uva11988
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

int n;
char s[N];
int nxt[N];

int main() {
#ifdef Test
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    while (~scanf("%s", s + 1)) {
        n = strlen(s + 1);
        nxt[0] = 0;  // 表示最左端
        // 如果某一位nxt[i]=0 ,也表示它是结尾
        int cur = 0, last = 0;  // 当前的光标和结尾光标

        _rep(i, 1, n) {
            char ch = s[i];
            if (ch == '[')
                cur = 0;  // 移到开头
            else if (ch == ']')
                cur = last;  // 移到结尾
            else {
                nxt[i] = nxt[cur];  // 更新第i位
                nxt[cur] = i;
                if (cur == last) last = i;  // 更新结尾
                cur = i;                    // 移动光标
            }
        }
        for (int i = nxt[0]; i; i = nxt[i]) {
            printf("%c", s[i]);
        }
        printf("\n");
    }
    return 0;
}