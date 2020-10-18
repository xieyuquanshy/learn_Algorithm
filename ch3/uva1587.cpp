/* uva1587
 * 2020/10/18
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
#define txt

map<int, int> mp;
int a[7][2];
int main() {
#ifdef txt
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (~scanf("%d%d", &a[0][0], &a[0][1])) {
        mp.clear();
        mp[a[0][0]]++;
        mp[a[0][1]]++;
        for (int i = 1; i < 6; ++i) {
            scanf("%d%d", &a[i][0], &a[i][1]);
            mp[a[i][0]]++, mp[a[i][1]]++;
        }
        if (sz(mp) == 1) {
            puts("POSSIBLE");
        } else if (sz(mp) == 2) {
            bool f = false;
            for (auto it = mp.begin(); it != mp.end(); ++it) {
                if (it->second == 4) {
                    int cnt = 0;
                    for (int i = 0; i < 7; ++i) {
                        if (a[i][0] == it->first || a[i][1] == it->first) cnt++;
                    }
                    if (cnt == 4) {
                        f = true;
                        break;
                    }
                }
                if (f) {
                    break;
                }
            }
            if (f)
                puts("POSSIBLE");
            else
                puts("IMPOSSIBLE");
        } else if (sz(mp) == 3) {
            bool f = true;
            for (auto it = mp.begin(); it != mp.end(); ++it) {
                if (it->second != 4) {
                    f = false;
                    break;
                }
                int cnt = 0;
                for (int i = 0; i < 7; ++i) {
                    if (a[i][0] == it->first || a[i][1] == it->first) cnt++;
                }
                if (cnt != 4) {
                    f = false;
                    break;
                }
            }
            if (f)
                puts("POSSIBLE");
            else
                puts("IMPOSSIBLE");
        } else {
            puts("IMPOSSIBLE");
        }
    }
    return 0;
}