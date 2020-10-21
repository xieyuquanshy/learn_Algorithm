/* uva489
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

int main() {
#ifdef txt
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int rnd;
    while (~scanf("%d", &rnd) && rnd != -1) {
        string s, p;
        cin >> s >> p;
        printf("Round %d\n", rnd);
        int wrg = 0, cor = 0;
        bool end = false, win = false;
        map<char, bool> word;
        _for(i, 0, sz(s)) word[s[i]] = false;
        _for(i, 0, sz(p)) {
            if (word.count(p[i]) && !word[p[i]]) {
                cor++;
                word[p[i]] = true;
            } else {
                wrg++;
            }
            if (cor == sz(word)) {
                win = true;
                break;
            }
            if (wrg == 7) {
                end = true;
                break;
            }
        }
        if (end)
            printf("You lose.\n");
        else if (win)
            printf("You win.\n");
        else
            printf("You chickened out.\n");
    }
    return 0;
}