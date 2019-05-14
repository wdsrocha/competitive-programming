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
#define N 40004

int n, l, r, open[N], close[N];

signed main() {
    cin >> n;
    int maxr = 0;
    for (int i = 1; i <= n; i++) {
        cin >> l >> r;
        open[l]++;
        close[r]++;
        maxr = max(maxr, r);
    }

    int ans = 0, ppl = 0;
    int cnt = 0;
    for (int i = 0; i <= maxr+1; i++) {
        ans = max(ans, cnt);

        if (open[i]) {
            cnt = 0;
            ppl += open[i];
        }

        if (close[i]) {
            ppl -= close[i];
        }

        if (!ppl) {
            cnt = 0;
        } else {
            cnt++;
        }
    }
    cout << ans << endl;

    return 0;
}
