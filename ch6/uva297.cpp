/* uva297
 * 2020/11/28
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

int buf[32][32];
char s[2014];
int cnt, n;

// 把s[idx...] 导出到[r,c]为左上起点，长度为len的矩形

void draw(const char* s, int& idx, int r, int c, int len) {
    if (idx >= n) return;
    char ch = s[idx++];
    if (ch == 'p') {
        draw(s, idx, r, c + len / 2, len / 2);            // 1
        draw(s, idx, r, c, len / 2);                      // 2
        draw(s, idx, r + len / 2, c, len / 2);            // 3
        draw(s, idx, r + len / 2, c + len / 2, len / 2);  // 4
    } else if (ch == 'f') {
        _for(i, r, r + len) {
            _for(j, c, c + len) {
                if (!buf[i][j]) {
                    buf[i][j] = 1;
                    cnt++;
                }
            }
        }
    }
}

int main() {
#ifdef Test
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int T;
    scanf("%d", &T);
    while (T--) {
        mem(buf, 0);
        cnt = 0;
        _for(i, 0, 2) {
            scanf("%s", s);
            n = strlen(s);
            int p = 0;
            draw(s, p, 0, 0, 32);
        }
        printf("There are %d black pixels.\n", cnt);
    }
    return 0;
}