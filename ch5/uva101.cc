/* uva101
 * 2020/10/24
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
vector<int> pile[30];

void find(int x, int &p, int &h) {
    _for(i, 0, n) {
        _for(j, 0, sz(pile[i])) {
            if (pile[i][j] == x) {
                p = i, h = j;
                return;
            }
        }
    }
}

void clear(int pa, int h) {
    _for(i, h + 1, sz(pile[pa])) {
        int b = pile[pa][i];
        pile[b].pb(b);
    }
    pile[pa].resize(h + 1);
}

void pileto(int p, int h, int p2) {
    _for(i, h, sz(pile[p])) { pile[p2].pb(pile[p][i]); }
    pile[p].resize(h);
}

void print() {
    _for(i, 0, n) {
        printf("%d:", i);
        _for(j, 0, sz(pile[i])) { printf(" %d", pile[i][j]); }
        printf("\n");
    }
}

int main() {
#ifdef txt
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    _for(i, 0, n) pile[i].pb(i);
    string a, b;
    int x, y;
    while (cin >> a) {
        if (a[0] == 'q') break;
        cin >> x >> b >> y;
        int px, py, hx, hy;
        find(x, px, hx);
        find(y, py, hy);
        if (px == py) continue;
        if (b == "onto") clear(py, hy);
        if (a == "move") clear(px, hx);
        pileto(px, hx, py);
    }
    print();
    return 0;
}