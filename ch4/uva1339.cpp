/* uva1339
 * 2020/10/21
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

int cnt1[30], cnt2[30];

int main() {
#ifdef txt
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    string a, b;
    while (cin >> a >> b) {
        mem(cnt1, 0);
        mem(cnt2, 0);
        for (char ch : a) cnt1[ch - 'A']++;
        for (char ch : b) cnt2[ch - 'A']++;
        sort(cnt1, cnt1 + 26);
        sort(cnt2, cnt2 + 26);
        bool ok = true;
        _for(i, 0, 26) {
            if (cnt1[i] != cnt2[i]) {
                ok = false;
                break;
            }
        }
        printf("%s\n", ok ? "YES" : "NO");
    }
    return 0;
}