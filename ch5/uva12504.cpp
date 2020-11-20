/* uva12504
 * 2020/11/20
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

map<string, string> dic1, dic2;
bool ok;
void solve(string &s, bool f) {
    if (sz(s) == 2) return;
    int len = sz(s);
    int l = 0, m = 0, r = 0;
    while (l != len - 1) {
        m = s.find(":", r);
        r = s.find(",", m);
        if (r == s.npos) {
            r = len - 1;
        }
        if (f) {
            dic2[s.substr(l + 1, m - l - 1)] = s.substr(m + 1, r - m - 1);
        } else {
            dic1[s.substr(l + 1, m - l - 1)] = s.substr(m + 1, r - m - 1);
        }

        l = r;
    }
}

void print(set<string> &_s, int i) {
    if (sz(_s) == 0) return;
    ok = true;
    bool f = true;
    for (string s : _s) {
        if (!f) printf(",");
        if (f) {
            switch (i) {
                case 0:
                    printf("+");
                    break;
                case 1:
                    printf("-");
                    break;
                default:
                    printf("*");
                    break;
                    break;
            }
            f = 0;
        }
        printf("%s", s.c_str());
    }
    printf("\n");
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
    getchar();
    while (T--) {
        dic1.clear(), dic2.clear();
        ok = false;

        string a, b;
        getline(cin, a);
        solve(a, 0);
        getline(cin, b);
        solve(b, 1);

        set<string> add, del, change;
        for (auto it = dic1.begin(); it != dic1.end(); ++it) {
            if (!dic2.count(it->first)) {
                // delete
                del.insert(it->first);
            } else if (dic2[it->first] != dic1[it->first]) {
                // change
                change.insert(it->first);
            }
        }

        for (auto it = dic2.begin(); it != dic2.end(); ++it) {
            // add
            if (!dic1.count(it->first)) add.insert(it->first);
        }

        print(add, 0), print(del, 1), print(change, 2);

        if (!ok) printf("No changes\n");

        printf("\n");
    }
    return 0;
}