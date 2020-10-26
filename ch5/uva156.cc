/* uva156
 * 2020/10/24
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

vector<string> words;
map<string, int> mp;

string get(string s) {
    string res = s;
    _for(i, 0, sz(res)) { res[i] = tolower(res[i]); }
    sort(all(res));
    return res;
}

int main() {
#ifdef txt
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    string s;
    while (cin >> s) {
        if (s[0] == '#') break;
        string r = get(s);
        mp[r]++;
        words.pb(s);
    }
    vector<string> ans;
    _for(i, 0, sz(words)) {
        if (mp[get(words[i])] == 1) ans.pb(words[i]);
    }
    sort(all(ans));
    _for(i, 0, sz(ans)) cout << ans[i] << endl;
    return 0;
}