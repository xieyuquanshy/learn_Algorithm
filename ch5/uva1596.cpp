/* uva1596
 * 2020/11/14
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
const int M = 1e4 + 10;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-5;
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pb(x) push_back(x)
#define bg begin()
#define ed end()
#define mem(x, a) memset(x, a, sizeof(x));
#define endl '\n'
#define _for(i, a, b) for (int i = a; i < b; ++i)
#define _rep(i, a, b) for (int i = a; i <= b; ++i)
#define mp make_pair
#define Test

map<char, int> arr_size;
map<pair<char, int>, int> m_arr;
map<pair<char, int>, bool> is_ass;
bool ok;

void add_arr(const string& s) {
    int pl = s.find("["), pr = s.rfind("]");
    arr_size[s[0]] = stoi(s.substr(pl + 1, pr - pl - 1));
}

int getSize(string s, int cnt) {
    // cout << s << endl;
    int pl = s.find("["), pr = s.rfind("]");
    // cout << pl << " " << pr << endl;
    if (pl == s.npos) {
        return stoi(s);
    }
    int ls = getSize(s.substr(pl + 1, pr - pl - 1), cnt + 1);
    // cout << ls << " " << cnt << endl;
    if (cnt >= 1) {
        if (!is_ass[mp(s[0], ls)]) {
            ok = false;
            return -1;
        }
    }
    if (ls >= arr_size[s[0]]) {
        ok = false;
        return -1;
    }
    if (!ok) return -1;
    // cout << m_arr[mp(s[0], ls)] << endl;
    return m_arr[mp(s[0], ls)];
}

int main() {
#ifdef Test
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    int pl, pr, pe;
    while (cin >> s and s[0] != '.') {
        ok = true;
        add_arr(s);
        int wr = 0, cnt = 1;
        // cout << s[0] << " " << arr_size[s[0]] << endl;
        while (cin >> s and s[0] != '.') {
            cnt++;
            if (wr) continue;  
            pe = s.find("=");
            if (pe == s.npos) {
                // 不是赋值
                add_arr(s);
            } else {
                string s1 = s.substr(2, pe - 3), s2 = s.substr(pe + 1);
                // cout << s1 << " " << s2 << endl;
                int ls = getSize(s1, 0), rs = getSize(s2, 1);
                // cout << ls << " " << rs << endl;

                if (ls >= arr_size[s[0]] || ls == -1 || !ok) {
                    wr = cnt;
                } else {
                    m_arr[mp(s[0], ls)] = rs;
                    is_ass[mp(s[0], ls)] = 1;
                }
            }
        }
        cout << wr << endl;

        arr_size.clear();
        m_arr.clear();
        is_ass.clear();
    }
    return 0;
}