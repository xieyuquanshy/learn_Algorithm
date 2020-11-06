/* uva10391
 * 2020/11/04
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
#define Test

int main() {
#ifdef Test
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    set<string> vs;
    while (cin >> s) {
        vs.insert(s);
    }
    for (auto &str : vs) {
        bool in = false;
        _for(i, 1, sz(str)) {
            string s1 = str.substr(0, i);
            string s2 = str.substr(i);
            if (vs.count(s1) && vs.count(s2)) {
                in = true;
                break;
            }
        }
        if (in)
            cout << str << endl;
    }
    return 0;
}