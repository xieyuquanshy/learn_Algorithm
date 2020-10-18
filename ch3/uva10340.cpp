/* uva10340
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
string p, t;

int main() {
#ifdef txt
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (cin >> p >> t) {
        int j = 0;
        bool f = true;
        for (int i = 0; i < sz(p); ++i) {
            while (j < sz(t) && t[j] != p[i]) j++;
            if (j == sz(t)) {
                f = false;
                break;
            }
            j++;
        }
        printf("%s\n", f ? "Yes" : "No");
    }
    return 0;
}