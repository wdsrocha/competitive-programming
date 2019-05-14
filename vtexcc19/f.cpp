#include <bits/stdc++.h>
using namespace std;
#define debug(args...) (Debugger()) , args
class Debugger {
    public:
        Debugger(const string sep = " | ") : first(1), sep(sep) {}
        template <typename T> Debugger& operator , (const T& arg) {
            if (first) first = false;
            else cerr << sep;
            cerr << arg;
            return *this;
        }
        ~Debugger() { cerr << endl; }
    private:
        bool first = true;
        string sep;
};
inline ostream& operator << (ostream& os, const string& data) {
    os << "\'"; for (auto c : data) os << c; return os << "\'";
}
template <typename T1, typename T2>
inline ostream& operator << (ostream& os, const pair <T1, T2>& data) {
    return os << "(" << data.first << ", " << data.second << ")";
}
template <typename T>
inline ostream& operator << (ostream& os, const vector <T>& data) {
    os << "["; for (T value : data) os << value << ", "; return os << "\b\b]";
}
template <typename T>
inline ostream& operator << (ostream& os, const set <T>& data) {
    os << "{"; for (T value : data) os << value << ", "; return os << "}";
}
template <typename T1, typename T2>
inline ostream &operator << (ostream& os, const map <T1, T2>& data) {
    os << "{"; for (auto [key, item] : data) os << key << ": " << item << ", "; return os << "\b\b}";
}
#define NAME(x) cerr << #x << " = " << x << endl;
#define int long long
#define ii pair <int, int>
#define st first
#define nd second
#define vi vector <int>
#define vii vector <ii>
#define vvi vector <vi>
#define vvii vector <vii>
#define pb push_back
#define eb emplace_back
#define oo (1000000000)
#define MOD (1000000007)
#define sz(x) ((int)((x).size()))
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
inline int fexp(int b, int e) { int x = 1; for (; e; e >>= 1, b = (b*b)%MOD) if (e&1) x = (x*b)%MOD; return x; }
#define N 200005

int n;
vector <set <int>> s(3);
vector <int> v[N];

signed main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        v[i] = vi(4);
        for (int j = 0; j < 3; j++) {
            cin >> v[i][j];
            s[j].insert(v[i][j]);
        }
        v[i][3] = i;
    }

    // for (int i = 0; i < n; i++) {
        // for (int j = 0; j < 4; j++) {
            // cout << setw(4) << v[i][j];
        // }
        // cout << endl;
    // }

    // cout << "sizes: ";
    for (int i = 0; i < 3; i++) {
        // cout << s[i].size() << ' ';
        if (s[i].size() != n) {
            return cout << "N\n", 0;
        }
    }

    set <vector <int> > ans;
    for (int j = 0; j < 3; j++) {
        sort(v, v+n, [j](vi& x, vi& y)->bool { return x[j] < y[j]; });
        vi cur;
        for (int i = 0; i < n; i++) {
            cur.push_back(v[i][3]);
        }
        // debug(cur);
        ans.insert(cur);
    }

    cout << (ans.size() == 1 ? 'S' : 'N') << endl;

    return 0;
}
