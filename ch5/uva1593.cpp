/* uva1593
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
#include <sstream>
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
vector<string> vs[1010];
int pos[1010];
int main() {
#ifdef txt
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    string s, buf;
    int row = 0;
    while (getline(cin, s)) {
        stringstream ss(s);
        while (ss >> buf) {
            pos[sz(vs[row])] = max(pos[sz(vs[row])], sz(buf));
            vs[row].pb(buf);
        }
        row++;
    }
    _for(i, 0, row) {
        _for(j, 0, sz(vs[i])) {
            string st = vs[i][j];
            if (j != sz(vs[i]) - 1) {
                st += string(pos[j] - sz(st) + 1, ' ');
            }
            cout << st;
        }
        cout << endl;
    }
    return 0;
}