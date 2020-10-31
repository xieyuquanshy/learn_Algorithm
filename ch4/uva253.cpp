/* uva253
 * 2020/10/31
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

int d[3][4] = {{2, 4, 5, 3}, {2, 6, 5, 1}, {1, 4, 6, 3}};

void r(string &sr, int i, int j) {
    string s = sr;
    _for(k, 0, 4) { sr[d[i][k] - 1] = s[d[i][(j + k) % 4] - 1]; }
}

int main() {
#ifdef txt
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    string s;
    while (cin >> s) {
        string sa = s.substr(0, 6), sb = s.substr(6);
        bool same = false;
        _for(x, 0, 4) {
            _for(y, 0, 4) {
                _for(z, 0, 4) {
                    string st = sb;
                    r(st, 0, x);
                    r(st, 1, y);
                    r(st, 2, z);
                    if (st == sa) {
                        same = true;
                        break;
                    }
                }
                if (same) break;
            }
            if (same) break;
        }
        printf("%s\n", same ? "TRUE" : "FALSE");
    }
    return 0;
}