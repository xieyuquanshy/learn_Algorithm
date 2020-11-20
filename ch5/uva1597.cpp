/*
 * uva 1597
 * 2020/11/18
 */
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
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
#define mp make_pair
#define mem(x, a) memset(x, a, sizeof(x));
#define endl '\n'
#define _for(i, a, b) for (int i = a; i < b; ++i)
#define _rep(i, a, b) for (int i = a; i <= b; ++i)
#define mp make_pair
#define Test
int n;

vector<string> bucket[110];
map<string, bool> dic[110];
map<pair<int, pair<int, string>>, bool> pas;

string get_l(const string& s) {
    string res = s.substr(0, sz(s) - 1);
    for (auto& ch : res) ch = tolower(ch);
    if (isalpha(s.back())) res += tolower(s.back());
    return res;
}

void find(string& s) {
    s = get_l(s);
    bool f = true;
    _for(i, 0, n) {
        if (dic[i].count(s)) {
            if (!f) cout << "----------" << endl;
            _for(j, 0, sz(bucket[i])) {
                if (pas[mp(i, mp(j, s))]) {
                    cout << bucket[i][j] << endl;
                    if (f) f = false;
                }
            }
        }
    }
    if (f) cout << "Sorry, I found nothing." << endl;
}

void not_find(string& s) {
    s = get_l(s.substr(4));
    bool f = true;
    _for(i, 0, n) {
        if (!dic[i].count(s)) {
            if (!f) cout << "----------" << endl;
            _for(j, 0, sz(bucket[i])) {
                cout << bucket[i][j] << endl;
                if (f) f = 0;
            }
        }
    }
    if (f) cout << "Sorry, I found nothing." << endl;
}

void and_find(string& s) {
    int p = s.find("AND");
    string s1 = get_l(s.substr(0, p - 1)), s2 = get_l(s.substr(p + 4));
    bool f = 1;
    _for(i, 0, n) {
        if (dic[i].count(s1) and dic[i].count(s2)) {
            if (!f) cout << "----------" << endl;
            _for(j, 0, sz(bucket[i])) {
                if (pas[mp(i, mp(j, s1))] or pas[mp(i, mp(j, s2))]) {
                    cout << bucket[i][j] << endl;
                    if (f) f = false;
                }
            }
        }
    }
    if (f) cout << "Sorry, I found nothing." << endl;
}

void or_find(string& s) {
    int p = s.find("OR");
    string s1 = get_l(s.substr(0, p - 1)), s2 = get_l(s.substr(p + 3));
    bool f = 1;
    _for(i, 0, n) {
        if (dic[i].count(s1) || dic[i].count(s2)) {
            if (!f) cout << "----------" << endl;
            _for(j, 0, sz(bucket[i])) {
                if (pas[mp(i, mp(j, s1))] or pas[mp(i, mp(j, s2))]) {
                    cout << bucket[i][j] << endl;
                    if (f) f = false;
                }
            }
        }
    }
    if (f) cout << "Sorry, I found nothing." << endl;
}

int main() {
#ifdef Test
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    getchar();
    string buf, s;

    _for(c, 0, n) {
        int col = 0;
        while (getline(cin, s) && s[0] != '*') {
            // cout << s << endl;
            bucket[c].pb(s);
            stringstream ss(s);

            while (ss >> buf) {
                string temp = get_l(buf);
                // cout << temp << " ";
                dic[c][temp] = 1;
                pas[mp(c, mp(col, temp))] = 1;
            }
            col++;
        }
    }
    int Q;
    cin >> Q;
    getchar();
    while (Q--) {
        getline(cin, s);
        if (s.find("AND") != s.npos) {
            and_find(s);
        } else if (s.find("OR") != s.npos) {
            or_find(s);
        } else if (s.find("NOT") != s.npos) {
            not_find(s);
        } else {
            find(s);
        }
        cout << "==========" << endl;
    }
    return 0;
}
