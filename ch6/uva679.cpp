/* uva679
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

// int a[(1 << 20) - 1];

int main() {
#ifdef Test
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n;
    while (~scanf("%d", &n) && n != -1) {
        _for(i, 0, n) {
            // mem(a, 0);
            int d, l;
            scanf("%d%d", &d, &l);
            // int pre = -1;
            // _rep(j, 1, l) {
            //     int k = 1;
            //     while (k < (1 << d)) {
            //         pre = k;
            //         if (!a[k]) {
            //             a[k] = 1;
            //             k *= 2;
            //         } else {
            //             a[k] = 0;
            //             k = 2 * k + 1;
            //         }
            //     }
            // }
            int k = 1, pre = 0;
            while (k < (1 << d)) {
                pre = k;
                if (l % 2 == 1) {
                    k = 2 * k;
                    l = (l + 1) / 2;
                } else {
                    k = 2 * k + 1;
                    l /= 2;
                }
            }
            printf("%d\n", pre);
        }
    }
    return 0;
}