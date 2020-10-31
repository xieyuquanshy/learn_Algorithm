/* uva1590
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

string st[1010];
int n;
string getTwo(int num) {
    string bt;
    while (num) {
        char ch = num % 2 + '0';
        bt = ch + bt;
        num /= 2;
    }
    while (sz(bt) < 8) bt = '0' + bt;
    return bt;
}

int getNum(string s) {
    int num = 0;
    for (int i = 0; i <= 7; ++i) {
        num = num * 2 + (s[i] - '0');
    }
    return num;
}

bool check(int p) {
    _for(i, 1, n) {
        if (st[i][p] != st[i - 1][p]) return false;
    }
    return true;
}

int main() {
#ifdef txt
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (cin >> n) {
        _for(i, 0, n) {
            int a, b, c, d;
            scanf("%d.%d.%d.%d", &a, &b, &c, &d);
            st[i] = getTwo(a) + getTwo(b) + getTwo(c) + getTwo(d);
            // cout << st[i] << endl;
        }
        // cout << endl;
        string tt, ym;
        _for(i, 0, 32) {
            if (!check(i)) {
                _for(j, i, 32) tt += '0', ym += '0';
                break;
            }
            tt += st[0][i];
            ym += '1';
        }
        // cout << tt << endl;
        // cout << ym << endl;
        _for(i, 0, 4) {
            string tmp = tt.substr(8 * i, 8);
            int num = getNum(tmp);
            // cout << tmp << endl;
            printf("%s%d", i == 0 ? "" : ".", num);
        }
        printf("\n");
        _for(i, 0, 4) {
            string tmp = ym.substr(8 * i, 8);
            int num = getNum(tmp);
            // cout << tmp << endl;
            printf("%s%d", i == 0 ? "" : ".", num);
        }
        printf("\n");
    }
    return 0;
}