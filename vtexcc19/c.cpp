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
#define N 1003
#define WHITE 0
#define GREY 1
#define BLACK 2

void show();

int di[256], dj[256];
int n, m, cycle_id, cycle_cnt[N*N], f[N][N], color[N][N], cycle[N][N];
int mark[N][N]; // ;)
string grid[N];

int dfs_cycle(int i, int j) {
    if (i < 0 or i >= n or j < 0 or j >= m or color[i][j] == BLACK) {
        return 0;
    } else if (color[i][j] == GREY) {
        mark[i][j] = 1;
        return ++cycle_id;
    }

    color[i][j] = GREY;
    cycle[i][j] = dfs_cycle(i+di[grid[i][j]], j+dj[grid[i][j]]);
    cycle_cnt[cycle[i][j]] += (cycle[i][j] != 0);
    color[i][j] = BLACK;
    if (mark[i][j]) {
        mark[i][j] = 0;
        return 0;
    } else {
        return cycle[i][j];
    }
}

int dfs_cnt(int i, int j) {
    if (i < 0 or i >= n or j < 0 or j >= m) {
        return 0;
    } else if (color[i][j] != WHITE) {
        return f[i][j];
    }
    color[i][j] = GREY;
    f[i][j] = 1+dfs_cnt(i+di[grid[i][j]], j+dj[grid[i][j]]);
    color[i][j] = BLACK;
    return f[i][j];
}

signed main() {
    di['N'] =-1, dj['N'] = 0;
    di['S'] = 1, dj['S'] = 0;
    di['E'] = 0, dj['E'] = 1;
    di['W'] = 0, dj['W'] =-1;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    int sum = 0;

    // get cycles!!!
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (color[i][j] != WHITE) continue;
            dfs_cycle(i, j);
        }
    }

    // set cycle values and paint them black
    memset(color, WHITE, sizeof color);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (cycle[i][j]) {
                color[i][j] = BLACK;
                f[i][j] = cycle_cnt[cycle[i][j]];
            }
        }
    }

    // show();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (color[i][j] == WHITE) {
                dfs_cnt(i, j);
            }
        }
    }

    // show();

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans += f[i][j];
        }
    }
    cout << ans << endl;

    return 0;
}

void show() {
    printf("######################\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << setw(3) << f[i][j];
        }
        cout << endl;
    }
    printf("######################\n\n");
}
