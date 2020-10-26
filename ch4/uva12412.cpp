/* uva12412
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
const double eps = 1e-6;
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pb(x) push_back(x)
#define mem(x, a) memset(x, a, sizeof(x));
#define endl '\n'
#define _for(i, a, b) for (int i = a; i < b; ++i)
#define _rep(i, a, b) for (int i = a; i <= b; ++i)
#define txt

struct Student {
    ll sid;
    int cid;
    string name;
    int chi, math, eng, com, sum;
    Student() {}
    Student(ll sid, int cid, string name, int chi, int math, int eng, int com)
        : sid(sid),
          cid(cid),
          name(name),
          chi(chi),
          math(math),
          eng(eng),
          com(com),
          sum(chi + math + eng + com) {}

    bool operator==(const Student &A) const {
        return A.sid == sid && A.cid == cid && name == A.name && A.chi == chi &&
               A.math == math && A.eng == eng && A.com == com;
    }
};

bool cmp(Student A, Student B) { return A.sum > B.sum; }


vector<Student> stu;
vector<Student> all_stu;
map<ll, string> sid_tab;

void menu() {
    cout << "Welcome to Student Performance Management System (SPMS).\n\n";
    cout << "1 - Add\n";
    cout << "2 - Remove\n";
    cout << "3 - Query\n";
    cout << "4 - Show ranking\n";
    cout << "5 - Show Statistics\n";
    cout << "0 - Exit\n\n";
}

void add() {
    ll sid;
    int cid, chi, math, eng, com;
    string name;
    do {
        cout << "Please enter the SID, CID, name and four scores. Enter 0 to "
                "finish.\n";
        cin >> sid;
        if (!sid) break;
        cin >> cid >> name >> chi >> math >> eng >> com;
        Student s(sid, cid, name, chi, math, eng, com);
        if (sid_tab.count(sid)) {
            cout << "Duplicated SID.\n";
        } else {
            stu.pb(s);
            sid_tab[sid] = name;
        }
    } while (1);
}

void del() {
    ll sid = -1;
    string name = "?";
    do {
        int cnt = 0;
        cout << "Please enter SID or name. Enter 0 to finish.\n";
        cin >> name;
        sid = -1;
        if (sz(name) == 1 && name[0] == '0') break;
        if (isdigit(name[0])) {
            sid = stol(name);
            name = "?";
        }
        for (auto it = stu.begin(); it != stu.end();) {
            if (it->sid == sid || it->name == name) {
                cnt++;
                sid_tab.erase(it->sid);
                stu.erase(it);
            } else {
                it++;
            }
        }
        printf("%d student(s) removed.\n", cnt);
    } while (1);
}

void query() {
    all_stu = stu;
    sort(all(all_stu), cmp);
    ll sid = -1;
    string name = "?";
    do {
        cout << "Please enter SID or name. Enter 0 to finish.\n";
        cin >> name;
        sid = -1;
        if (sz(name) == 1 && name[0] == '0') break;
        if (isdigit(name[0])) {
            sid = stol(name);
            name = "?";
        }
        for (auto it = stu.begin(); it != stu.end(); ++it) {
            if (it->sid == sid || it->name == name) {
                int rank = 0, pre = 0, cnt = 1;
                for (auto its = all_stu.begin(); its != all_stu.end(); ++its) {
                    if (its->sum == pre)
                        cnt++;
                    else {
                        pre = its->sum;
                        rank += cnt;
                        cnt = 1;
                    }
                    if (*its == *it) {
                        break;
                    }
                }
                printf("%d %010lld %d %s %d %d %d %d %d %.2f\n", rank, it->sid,
                       it->cid, it->name.c_str(), it->chi, it->math, it->eng,
                       it->com, it->sum, 1.00 * it->sum / 4.00 + eps);
            }
        }
    } while (1);
}

void check() {
    cout << "Please enter class ID, 0 for the whole statistics.\n";
    int cid;
    cin >> cid;
    int total = 0, chi_sum = 0, math_sum = 0, eng_sum = 0, com_sum = 0;
    vector<ll> fail[4];
    for (int i = 0; i < 4; ++i) fail[i].clear();
    map<ll, int> fp;
    fp.clear();
    for (auto it = stu.begin(); it != stu.end(); ++it) {
        if (it->cid == cid || !cid) {
            total++;
            chi_sum += it->chi;
            math_sum += it->math;
            eng_sum += it->eng;
            com_sum += it->com;
            if (it->chi < 60) fail[0].pb(0), fp[it->sid]++;
            if (it->math < 60) fail[1].pb(1), fp[it->sid]++;
            if (it->eng < 60) fail[2].pb(2), fp[it->sid]++;
            if (it->com < 60) fail[3].pb(3), fp[it->sid]++;
        }
    }
    printf(
        "Chinese\nAverage Score: %.2f\nNumber of passed students: %d\nNumber "
        "of "
        "failed students: %d\n\n",
        !total?0:1.00 * chi_sum / total + eps, total - sz(fail[0]), sz(fail[0]));
    printf(
        "Mathematics\nAverage Score: %.2f\nNumber of passed students: %d\n"
        "Number of "
        "failed students: %d\n\n",
        !total?0:1.00 * math_sum / total + eps, total - sz(fail[1]), sz(fail[1]));
    printf(
        "English\nAverage Score: %.2f\nNumber of passed students: %d\nNumber "
        "of "
        "failed students: %d\n\n",
        !total?0:1.00 * eng_sum / total + eps, total - sz(fail[2]), sz(fail[2]));
    printf(
        "Programming\nAverage Score: %.2f\nNumber of passed students: %d\n"
        "Number of "
        "failed students: %d\n\n",
        !total?0:1.00 * com_sum / total + eps, total - sz(fail[3]), sz(fail[3]));
    int three = 0, two = 0, one = 0, all = 0;
    for (auto it = stu.begin(); it != stu.end(); ++it) {
        if (fp.count(it->sid)) {
            three += fp[it->sid] <= 1;
            two += fp[it->sid] <= 2;
            one += fp[it->sid] <= 3;
            all += fp[it->sid] == 4;
        }
    }
    int ps = total - sz(fp);
    printf(
        "Overall:\nNumber of students who passed all subjects: %d\nNumber of "
        "students who passed 3 or more subjects: %d\nNumber of students who "
        "passed 2 or more subjects: %d\nNumber of students who passed 1 or "
        "more subjects: %d\nNumber of students who failed all subjects: %d\n\n",
        ps, three + ps, two + ps, one + ps, all);
}

int main() {
#ifdef txt
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int select;
    bool end = false;
    do {
        menu();
        cin >> select;
        switch (select) {
            case 1:
                add();
                break;
            case 2:
                del();
                break;
            case 3:
                query();
                break;
            case 4:
                printf(
                    "Showing the ranklist hurts students' self-esteem. Don'"
                    "t do that.\n");
                break;
            case 5:
                check();
                break;
            case 0:
                end = true;
                break;
        }
    } while (!end);
    return 0;
}