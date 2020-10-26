/* Untitled-1
 * 2020/10/23
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
const int M = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const double eps = 1e-5;
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pb(x) push_back(x)
#define mem(x, a) memset(x, a, sizeof(x));
#define endl '\n'
#define _for(i, a, b) for (int i = a; i < b; ++i)
#define _rep(i, a, b) for (int i = a; i <= b; ++i)
#define txt

struct Student {
    int A, B, C;
} a[15];
int n;
bool s[15];
int main() {
#ifdef txt
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int kase = 1;
    while (~scanf("%d", &n) && n) {
        mem(s, 0);
        int clear = 0, sleep = 0;
        _for(i, 0, n) {
            scanf("%d%d%d", &a[i].A, &a[i].B, &a[i].C);
            a[i].C %= (a[i].A + a[i].B);
            if (!a[i].C) a[i].C = a[i].A + a[i].B;
            if (a[i].C > a[i].A)
                s[i] = 1, sleep++;
            else
                clear++;
        }
        int ans = -1;
        _rep(t, 1, 10000) {
            bool ok = true;
            _for(i, 0, n) if (s[i]) {
                ok = false;
                break;
            }
            if (ok) {
                ans = t;
                break;
            }
            int c1 = 0, c2 = 0;
            _for(i, 0, n) {
                a[i].C++;
                a[i].C %= (a[i].A + a[i].B);
                if (!a[i].C) a[i].C = a[i].A + a[i].B;
                if (a[i].C > a[i].A && sleep > clear) {
                    if (!s[i]) c1++, s[i] = 1, c2--;
                } else {
                    if (a[i].C > a[i].A && sleep <= clear && !s[i]) a[i].C = 1;
                    if (s[i] && a[i].C == 1) c1--, c2++, s[i] = 0;
                }
            }
            sleep += c1, clear += c2;
        }

        printf("Case %d: %d\n", kase++, ans);
    }
    return 0;
}