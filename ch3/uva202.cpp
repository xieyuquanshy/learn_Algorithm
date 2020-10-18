/* uva202
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
const int N = 3e4 + 10;
const int M = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const double eps = 1e-5;
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pb(x) push_back(x)
#define mem(x, a) memset(x, a, sizeof(x));
#define endl '\n'
#define txt

int a, b;
vector<int> d;
int table[N];
int main() {
#ifdef txt
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (~scanf("%d%d", &a, &b)) {
        d.clear();
        mem(table, -1);
        int cnt = 0;
        printf("%d/%d = %d.", a, b, a / b);
        table[a % b] = cnt;
        a %= b;
        a *= 10;
        while (1) {
            d.pb(a / b);
            a %= b;
            cnt++;
            if (table[a] != -1) {
                int p = 0;
                for (int i = 0; i < table[a]; ++p, ++i) printf("%d", d[i]);
                printf("(");
                for (int i = table[a]; i < cnt && p < 50; ++p, ++i)
                    printf("%d", d[i]);
                if (p == 50) printf("...");
                printf(")\n");
                printf("   %d = number of digits in repeating cycle\n\n",
                       cnt - table[a]);
                break;
            } else {
                table[a] = cnt;
                a *= 10;
            }
        }
    }
    return 0;
}