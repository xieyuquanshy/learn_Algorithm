/* uva230
 * 2020/11/06
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
#define Test

struct Book {
    string tit, ath;
    Book() {}
    Book(string tit, string ath) : ath(ath), tit(tit) {}
};

vector<Book> book;

bool cmp(Book A, Book B) {
    if (A.ath == B.ath)
        return A.tit < B.tit;
    return A.ath < B.ath;
}

map<string, string> author;

vector<Book> bor, ret;

void show() {
    cout << "The book: \n";
    _for(i, 0, sz(book)) { cout << book[i].tit << " " << book[i].ath << endl; }
    cout << endl;
}

int main() {
#ifdef Test
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    string s;
    while (getline(cin, s)) {
        if (s == "END")
            break;
        string s1, s2;
        int pos = s.find("by");
        s1 = s.substr(0, pos - 1); // title
        s2 = s.substr(pos + 3);    // author
        book.pb(Book(s1, s2));
        author[s1] = s2;
    }
    sort(all(book), cmp);
    // show();
    while (getline(cin, s)) {
        if (s == "END")
            break;
        if (s[0] == 'S') {
            sort(all(ret), cmp);
            for (int i = 0; i < sz(ret); ++i) {
                auto it = book.begin();
                while (it != book.end() &&
                       (it->ath < ret[i].ath ||
                        (it->ath == ret[i].ath && it->tit < ret[i].tit)))
                    it++;
                book.insert(it, ret[i]);
                if (it == book.begin()) {
                    printf("Put %s first\n", ret[i].tit.c_str());
                } else {
                    printf("Put %s after %s\n", ret[i].tit.c_str(),
                           (it - 1)->tit.c_str());
                }
            }
            printf("END\n");
            ret.clear();
        } else {
            int pos = s.find("\"");
            string title = s.substr(pos);
            // cout << title << endl;
            if (s[0] == 'B') {
                for (auto it = book.begin(); it != book.end(); ++it) {
                    if (it->tit == title) {
                        book.erase(it);
                        break;
                    }
                }
                bor.push_back(Book(title, author[title]));
                // show();
            } else {
                for (auto it = bor.begin(); it != bor.end(); ++it) {
                    if (it->tit == title) {
                        bor.erase(it);
                        break;
                    }
                }
                ret.push_back(Book(title, author[title]));
            }
        }
    }

    return 0;
}