/* uva400
 * 2020/10/26
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

int n;

void show(const string &s, int len, char ex = ' ') {
    cout << s;
    _for(i, 0, len - sz(s)) { cout << ex; }
}

int main() {
#ifdef txt
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (~scanf("%d", &n)) {
        vector<string> w(n);
        int mw = 0;
        _for(i, 0, n) {
            cin >> w[i];
            mw = max(mw, sz(w[i]));
        }
        int mcol = (60 - mw) / (mw + 2) + 1, mrow = (n - 1) / mcol + 1;
        sort(all(w));
        show("", 60, '-');
        cout << endl;
        _for(i, 0, mrow) {
            _for(j, 0, mcol) {
                int c = j * mrow + i;
                if (c >= n) continue;
                int len = j == mcol - 1 ? mw : mw + 2;
                show(w[c], len);
            }
            cout << endl;
        }
    }
    return 0;
}