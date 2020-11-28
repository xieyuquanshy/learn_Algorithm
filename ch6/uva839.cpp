/* uva839
 * 2020/11/26
 * ac: 2020年11月27日22:53:44
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

struct node {
    int wl = 0, d1 = 0, d2 = 0, wr = 0, id = 0;
    node *l, *r;
    node(node* l = nullptr, node* r = nullptr) : l(l), r(r) {}
} * root;

int arr[N][4];

node* build(int& idx) {
    node* tmp = new node();
    tmp->wl = arr[idx][0];
    tmp->wr = arr[idx][2];
    tmp->d1 = arr[idx][1];
    tmp->d2 = arr[idx][3];
    tmp->id = idx;
    if (tmp->wl == 0) {
        tmp->l = build(++idx);
    }
    if (tmp->wr == 0) {
        tmp->r = build(++idx);
    }

    return tmp;
}

bool flag;
int gw(node* cur) {
    if (!cur) return 0;
    int nl = cur->wl + gw(cur->l), nr = cur->wr + gw(cur->r);
    // cout << nl << " " << nr << endl;
    if (nl == -1 || nr == -1) return -1;
    if (nl * cur->d1 != nr * cur->d2) {
        flag = false;
        return -1;
    }
    return nl + nr;
}

int main() {
#ifdef Test
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n;
    scanf("%d ", &n);
    string s;
    // getchar();
    _for(idx, 0, n) {
        flag = true;
        // getchar();
        int row = 0;
        while (getline(cin, s) && !s.empty()) {
            // get data
            stringstream ss(s);
            // cout << s << endl;
            int x, j = 0;
            while (ss >> x) arr[row][j++] = x;
            row++;
        }
        // _for(i, 0, row) {
        //     _for(j, 0, 4) cout << arr[i][j] << " ";
        //     cout << endl;
        // }
        // cout << endl;
        int k = 0;
        root = build(k);
        gw(root);
        printf("%s\n%s", flag ? "YES" : "NO", idx != n - 1 ? "\n" : "");
        // getchar();
        // cout << endl;
        // if (idx != n - 1) getchar();
    }
    return 0;
}