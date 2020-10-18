/* uva1586
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

double get(char ch, int num) {
    if (ch == 'C')
        return num * 12.01;
    else if (ch == 'H')
        return num * 1.008;
    else if (ch == 'O')
        return num * 16.00;
    else if (ch == 'N')
        return num * 14.01;
    else
        return 0.0;
}

int main() {
#ifdef txt
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while (T--) {
        string s;
        cin >> s;
        double sum = 0.0;
        int cnt = 0;
        for (int i = 0; i < sz(s); ++i) {
            if (isalpha(s[i])) {
                int j = i + 1;
                while (j < sz(s) and isdigit(s[j])) {
                    cnt = cnt * 10 + (s[j] - '0');
                    j++;
                }
                if (cnt == 0) cnt = 1;
                sum += get(s[i], cnt);
                cnt = 0;
            } else {
                continue;
            }
        }
        printf("%.3f\n", sum);
    }
    return 0;
}