/* uva213
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

int code[8][1 << 8];

int readChar() {
    char ch;
    while (1) {
        ch = getchar();
        if (ch != '\n' && ch != '\r') return ch;
    }
    return 0;
}

int readInt(int c) {
    int v = 0;
    while (c--) v = v * 2 + readChar() - '0';
    return v;
}

int readCode() {
    mem(code, 0);
    code[1][0] = readChar();
    for (int len = 2; len <= 7; ++len) {
        for (int val = 0; val < (1 << len) - 1; ++val) {
            int ch = getchar();
            if (ch == EOF) return 0;
            if (ch == '\n' || ch == '\r') return 1;
            code[len][val] = ch;
        }
    }
    return 1;
}

int main() {
#ifdef txt
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    string s;
    while (readCode()) {
        while (1) {
            int p = readInt(3);
            if (!p) break;
            for (;;) {
                int n = readInt(p);
                if (n == (1 << p) - 1) break;
                putchar(code[p][n]);
            }
        }
        putchar('\n');
    }
    return 0;
}