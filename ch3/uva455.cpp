/* uva455
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

string s;
int n;

bool check(int k) {
    for (int i = 0; i < n - k; ++i) {
        if (s[i] != s[i + k]) return false;
    }
    return true;
}

int main() {
#ifdef txt
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    for (int ka = 1; ka <= T; ++ka) {
        cin >> s;
        n = sz(s);
        int ans = n;
        for (int k = 1; k <= n / 2; ++k) {
            if (n % k == 0 and check(k) and ans > k) {
                ans = k;
            }
        }
        printf("%d\n", ans);
        if (ka != T) printf("\n");
    }
    return 0;
}