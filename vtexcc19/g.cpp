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
#define ll long long
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
#define N 100005

int INF = 2;
ll n, k;
ii ans[N+9];

struct Customer {
    ll i, t, d;
} v[N];

signed main() {
    INF = fexp(INF, 127);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> v[i].t >> v[i].d;
        v[i].i = i;
    }

    sort(v+1, v+n+1, [](Customer x, Customer y)->bool {
        if (x.t != y.t) return x.t < y.t;
        return x.i < y.i;
    });

    int fa = 0, fb = 0;
    queue <int> qa, qb;
    for (int i = 1; i <= n; i++) {
        while (qa.size() and qa.front() <= v[i].t) qa.pop();
        while (qb.size() and qb.front() <= v[i].t) qb.pop();
        if (qa.size() <= qb.size()) {
            fa = max(fa, v[i].t)+v[i].d;
            qa.push(fa);
            ans[v[i].i] = ii('A', fa);
        } else {
            fb = max(fb, v[i].t)+k*v[i].d;
            qb.push(fb);
            ans[v[i].i] = ii('B', fb);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << (char)ans[i].first << ' ' << ans[i].second << endl;
    }

    return 0;
}
