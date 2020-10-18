/* uva11809
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

int main() {
#ifdef txt
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    double a;
    int b;
    while (~scanf("%17lfe%d", &a, &b) && (b || a)) {
        a = log(a) + b * log(10);
        for (int e = 1; e <= 30; ++e) {
            for (int m = 0; m <= 9; ++m) {
                double mm = 0, ee = 0;
                for (int i = 0; i <= m; ++i) mm += 1, mm /= 2;
                for (int i = 1; i <= e; ++i) ee *= 2, ee += 1;
                if (abs(log(mm) + ee * log(2) - a) < eps) {
                    cout << m << " " << e << endl;
                }
            }
        }
    }
    return 0;
}