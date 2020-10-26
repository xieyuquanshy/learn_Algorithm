/* uva12096
 * 2020/10/25
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

map<set<int>, int> IDcache;
vector<set<int>> Setcache;

int ID(set<int> s) {
    if (IDcache.count(s)) return IDcache[s];
    Setcache.pb(s);
    return IDcache[s] = sz(Setcache) - 1;
}

int main() {
#ifdef txt
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        stack<int> s;
        IDcache.clear();
        Setcache.clear();
        _for(i, 0, n) {
            string op;
            cin >> op;
            if (op[0] == 'P')
                s.push(ID(set<int>()));
            else if (op[0] == 'D')
                s.push(s.top());
            else {
                set<int> x1 = Setcache[s.top()];
                s.pop();
                set<int> x2 = Setcache[s.top()];
                s.pop();
                set<int> x;
                if (op[0] == 'U')
                    set_union(all(x1), all(x2), inserter(x, x.begin()));
                if (op[0] == 'I')
                    set_intersection(all(x1), all(x2), inserter(x, x.begin()));
                if (op[0] == 'A') {
                    x = x2;
                    x.insert(ID(x1));
                }
                s.push(ID(x));
            }
            printf("%d\n", sz(Setcache[s.top()]));
        }
        printf("***\n");
    }
    return 0;
}