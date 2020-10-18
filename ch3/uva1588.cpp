/* uva1588
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

string s, t;
int n1, n2;
bool check(int p) {
    for (int i = p; i < n2 && i - p < n1; ++i) {
        int num1 = s[i - p] - '0', num2 = t[i] - '0';
        if (num1 + num2 > 3) {
            return false;
        }
    }
    return true;
}

int main() {
#ifdef txt
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (cin >> s >> t) {
        n1 = sz(s), n2 = sz(t);
        int ans = n2 + n1;
        for (int i = 0; i < n2; ++i) {
            if (check(i)) {
                if (n1 + i > n2)
                    ans = n1 + i;
                else
                    ans = n2;
                break;
            }
        }
        swap(s, t);
        swap(n1, n2);
        for (int i = 0; i < n2; ++i) {
            if (check(i)) {
                if (n1 + i > n2)
                    ans = min(ans, n1 + i);
                else
                    ans = min(ans, n2);
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}