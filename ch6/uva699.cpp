/* uva699
 * 2020/11/27
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

map<int, int> cnt;

void build(int pos) {
    int v;
    cin >> v;
    if (v == -1) return;
    cnt[pos] += v;
    build(pos - 1);
    build(pos + 1);
}

bool init() {
    cnt.clear();
    int v;
    cin >> v;
    if (v == -1) return false;
    cnt[0] = v;
    build(-1);
    build(1);
    return true;
}

int main() {
#ifdef Test
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int kase = 1;
    while (init()) {
        printf("Case %d:\n", kase++);
        for (auto p : cnt) {
            printf("%d%s", p.second,
                   p.first == cnt.rbegin()->first ? "\n" : " ");
        }
        puts("");
    }
    return 0;
}