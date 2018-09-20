#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);
#define endl '\n'
#define INF ((int)1e9)
#define MOD7 (INF + 7)
#define MOD11 (INF + 11)
#define EPS (1e-9)
#define PI (acos(-1))
#define SZ(x) ((int)x.size())
#define eb emplace_back
#define pb eb
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define int ll
#define ii pair <int, int>
#define vi vector <int>
#define vii vector <ii>
#define vvi vector <vi>
#define vvii vector <vii>
#define dd pair <double, double>
#define vd vector <double>
#define vdd vector <dd>
#define vvd vector <vd>
#define vvdd vector <vdd>
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cout<<#x<<" is "<<x<<endl;

struct Segment {
    int l, r;
};

int n, m;
vector <string> grid;
map <char, Segment> segment;

bool segmentContains(char c) {
    return segment.find(c) != segment.end();
}

bool isInsideGrid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

void fillLeftAndRight(int i, int j, char c) {
    if (!isInsideGrid(0, j) || grid[i][j] != '?') {
        return;
    }

    grid[i][j] = c;
    segment[c].l = min(segment[c].l, j);
    segment[c].r = max(segment[c].r, j);
    fillLeftAndRight(i, j-1, c);
    fillLeftAndRight(i, j+1, c);
}

void fillUpAndDown(int i, int l, int r, int c) {
    if (!isInsideGrid(i, 0)) {
        return;
    }
    
    for (int j = l; j <= r; j++) {
        if (grid[i][j] != '?') {
            return;
        }
    }

    for (int j = l; j <= r; j++) {
        grid[i][j] = c;
    }

    fillUpAndDown(i-1, l, r, c);
    fillUpAndDown(i+1, l, r, c);
}

signed main() {
    int TC;
    cin >> TC;
    for (int tc = 1; tc <= TC; tc++) {
        cin >> n >> m;
        grid = vector <string>(n);
        segment.clear();
        for (int i = 0; i < n; i++)
            cin >> grid[i];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char c = grid[i][j];
                if (c != '?' && !segmentContains(c)) {
                    segment[c].l = j;
                    for (int k = j; k < m && grid[i][k] == c; k++) {
                        segment[c].r = k;
                    }
                    fillLeftAndRight(i, j-1, c);
                    fillLeftAndRight(i, j+1, c);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char c = grid[i][j];
                if (c != '?') {
                    fillUpAndDown(i-1, segment[c].l, segment[c].r, c);
                    fillUpAndDown(i+1, segment[c].l, segment[c].r, c);
                }
            }
        }

        cout << "Case #" << tc << ":";
        cout << endl;
        for (int i = 0; i < n; i++)
            cout << grid[i] << endl;
    }
    return 0;
}
