/* uva401
 * 2020/10/17
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
#define txt

char t[] = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";

const char* msg[] = {"is not a palindrome.", "is a regular palindrome.",
                     "is a mirrored string.", "is a mirrored palindrome."};

// 判断回文串
bool pal(char* s, int len) {
    for (int i = 0; i < (len + 1) / 2; ++i) {
        if (s[i] != s[len - i - 1]) return false;
    }
    return true;
}

char getMir(char ch) {
    if (isalpha(ch))
        return t[ch - 'A'];
    else
        return t[ch - '0' + 25];
}

bool mir(char* s, int len) {
    for (int i = 0; i < (len + 1) / 2; ++i) {
        if (getMir(s[i]) != s[len - i - 1]) return false;
    }
    return true;
}

int main() {
#ifdef txt
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    char s[100];
    while (scanf("%s", s) == 1) {
        int len = strlen(s);
        int f1 = pal(s, len);
        int f2 = mir(s, len);
        printf("%s -- %s\n\n", s, msg[f2 * 2 + f1]);
    }
    return 0;
}