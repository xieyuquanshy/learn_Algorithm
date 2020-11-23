/* uva122
 * 2020/11/23
 *
 * 树的层次遍历
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
#define mp make_pair
#define mem(x, a) memset(x, a, sizeof(x));
#define endl '\n'
#define _for(i, a, b) for (int i = a; i < b; ++i)
#define _rep(i, a, b) for (int i = a; i <= b; ++i)
#define Test

struct node {
    int val;
    node *l, *r;
    node(int val = -1, node* l = nullptr, node* r = nullptr)
        : val(val), l(l), r(r) {}
} * root;

char s[101];
bool ok;

void add(int& val, char* pos) {
    int len = strlen(pos);
    node* cur = root;
    _for(i, 0, len) {
        if (pos[i] == 'L') {
            if (cur->l == nullptr) {
                cur->l = new node();
            }
            cur = cur->l;
        } else if (pos[i] == 'R') {
            if (cur->r == nullptr) {
                cur->r = new node();
            }
            cur = cur->r;
        }
    }
    if (cur->val != -1) {
        ok = false;
    } else {
        cur->val = val;
    }
}

void print() {
    node* cur;
    queue<node*> q;
    q.push(root);
    vector<int> ans;
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        if (cur->val != -1) {
            ans.pb(cur->val);
        } else {
            ok = false;
            break;
        }
        if (cur->l) q.push(cur->l);
        if (cur->r) q.push(cur->r);
    }
    if (!ok) {
        printf("not complete\n");
    } else {
        _for(i, 0, sz(ans)) {
            printf("%d%s", ans[i], i == sz(ans) - 1 ? "\n" : " ");
        }
    }
}

int main() {
#ifdef Test
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    while (1) {
        root = new node();
        ok = true;
        while (1) {
            if (scanf("%s", s) != 1) return 0;
            if (!strcmp(s, "()")) break;
            int val;
            sscanf(&s[1], "%d", &val);
            add(val, strchr(s, ',') + 1);
        }
        if (!ok) {
            printf("not complete\n");
            continue;
        }
        print();
    }
    return 0;
}