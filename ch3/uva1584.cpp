/* uva1584
 * 2020/10/18
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

char s[300];
int len;
bool check(int now, int p) {
    for (int i = 0; i < len; ++i) {
        if (s[p + i] == s[now + i])
            continue;
        else {
            return s[p + i] > s[now + i];
        }
    }
    return false;
}

int main() {
#ifdef txt
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        len = strlen(s);
        for (int i = len; i < 2 * len; ++i) {
            s[i] = s[i - len];
        }
        int p = 0;
        for (int i = 1; i < len; ++i) {
            if (check(i, p)) {
                p = i;
            }
        }

        for (int i = 0; i < len; ++i) {
            printf("%c", s[i + p]);
        }
        printf("\n");
    }
    return 0;
}