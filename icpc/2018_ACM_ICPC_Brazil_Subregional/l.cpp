#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define eb emplace_back

template<class T>
class heavy_light {
    static const bool VALUES_ON_EDGES = false;

    static T join_values(const T &a, const T &b) {
        return a+b;
    }

    static T join_value_with_delta(const T &v, const T &d, int len) {
        return v+d*len;
    }

    static T join_deltas(const T &d1, const T &d2) {
        return d1+d2;
    }

    int counter, paths;
    vector<vector<T> > value, delta;
    vector<vector<bool> > pending;
    vector<vector<int> > len;
    vector<int> size, parent, tin, tout, path, pathlen, pathpos, pathroot;
    vector<int> *adj;

    void dfs(int u, int p) {
        tin[u] = counter++;
        parent[u] = p;
        size[u] = 1;
        for (int j = 0; j < (int)adj[u].size(); j++) {
            int v = adj[u][j];
            if (v != p) {
                dfs(v, u);
                size[u] += size[v];
            }
        }
        tout[u] = counter++;
    }

    int new_path(int u) {
        pathroot[paths] = u;
        return paths++;
    }

    void build_paths(int u, int path) {
        this->path[u] = path;
        pathpos[u] = pathlen[path]++;
        for (int j = 0; j < (int)adj[u].size(); j++) {
            int v = adj[u][j];
            if (v != parent[u]) {
                build_paths(v, (2*size[v] >= size[u]) ? path : new_path(v));
            }
        }
    }

    inline T join_value_with_delta(int path, int i) {
        return pending[path][i]
            ? join_value_with_delta(value[path][i], delta[path][i], len[path][i])
            : value[path][i];
    }

    void push_delta(int path, int i) {
        int d = 0;
        while ((i >> d) > 0) {
            d++;
        }
        for (d -= 2; d >= 0; d--) {
            int l = (i >> d), r = (l ^ 1), n = l/2;
            if (pending[path][n]) {
                value[path][n] = join_value_with_delta(path, n);
                delta[path][l] =
                    pending[path][l] ? join_deltas(delta[path][l], delta[path][n])
                    : delta[path][n];
                delta[path][r] =
                    pending[path][r] ? join_deltas(delta[path][r], delta[path][n])
                    : delta[path][n];
                pending[path][l] = pending[path][r] = true;
                pending[path][n] = false;
            }
        }
    }

    bool query(int path, int u, int v, T *res) {
        push_delta(path, u += value[path].size()/2);
        push_delta(path, v += value[path].size()/2);
        bool found = false;
        for (; u <= v; u = (u + 1)/2, v = (v - 1)/2) {
            if ((u & 1) != 0) {
                T value = join_value_with_delta(path, u);
                *res = found ? join_values(*res, value) : value;
                found = true;
            }
            if ((v & 1) == 0) {
                T value = join_value_with_delta(path, v);
                *res = found ? join_values(*res, value) : value;
                found = true;
            }
        }
        return found;
    }

    void update(int path, int u, int v, const T &d) {
        push_delta(path, u += value[path].size()/2);
        push_delta(path, v += value[path].size()/2);
        int tu = -1, tv = -1;
        for (; u <= v; u = (u + 1)/2, v = (v - 1)/2) {
            if ((u & 1) != 0) {
                delta[path][u] = pending[path][u] ? join_deltas(delta[path][u], d) : d;
                pending[path][u] = true;
                if (tu == -1) {
                    tu = u;
                }
            }
            if ((v & 1) == 0) {
                delta[path][v] = pending[path][v] ? join_deltas(delta[path][v], d) : d;
                pending[path][v] = true;
                if (tv == -1) {
                    tv = v;
                }
            }
        }
        for (int i = tu; i > 1; i /= 2) {
            value[path][i/2] = join_values(join_value_with_delta(path, i),
                    join_value_with_delta(path, i ^ 1));
        }
        for (int i = tv; i > 1; i /= 2) {
            value[path][i/2] = join_values(join_value_with_delta(path, i),
                    join_value_with_delta(path, i ^ 1));
        }
    }

    inline bool is_ancestor(int parent, int child) {
        return (tin[parent] <= tin[child]) && (tout[child] <= tout[parent]);
    }

    public:
    heavy_light(int n, vector<int> adj[], const T &v = T())
        : counter(0), paths(0), size(n), parent(n), tin(n), tout(n), path(n),
        pathlen(n), pathpos(n), pathroot(n), adj(adj) {
            dfs(0, -1);
            build_paths(0, new_path(0));
            value.resize(paths);
            delta.resize(paths);
            pending.resize(paths);
            len.resize(paths);
            for (int i = 0; i < paths; i++) {
                int m = pathlen[i];
                value[i].assign(2*m, v);
                delta[i].resize(2*m);
                pending[i].assign(2*m, false);
                len[i].assign(2*m, 1);
                for (int j = 2*m - 1; j > 1; j -= 2) {
                    value[i][j/2] = join_values(value[i][j], value[i][j ^ 1]);
                    len[i][j/2] = len[i][j] + len[i][j ^ 1];
                }
            }
        }

    T query(int u, int v) {
        if (VALUES_ON_EDGES && u == v) {
            throw runtime_error("No edge between u and v to be queried.");
        }
        bool found = false;
        T res = T(), value;
        int root;
        while (!is_ancestor(root = pathroot[path[u]], v)) {
            if (query(path[u], 0, pathpos[u], &value)) {
                res = found ? join_values(res, value) : value;
                found = true;
            }
            u = parent[root];
        }
        while (!is_ancestor(root = pathroot[path[v]], u)) {
            if (query(path[v], 0, pathpos[v], &value)) {
                res = found ? join_values(res, value) : value;
                found = true;
            }
            v = parent[root];
        }
        if (query(path[u], min(pathpos[u], pathpos[v]) + (int)VALUES_ON_EDGES,
                    max(pathpos[u], pathpos[v]), &value)) {
            res = found ? join_values(res, value) : value;
            found = true;
        }
        if (!found) {
            throw runtime_error("Unexpected error: No values found.");
        }
        return res;
    }

    void update(int u, int v, const T &d) {
        if (VALUES_ON_EDGES && u == v) {
            return;
        }
        int root;
        while (!is_ancestor(root = pathroot[path[u]], v)) {
            update(path[u], 0, pathpos[u], d);
            u = parent[root];
        }
        while (!is_ancestor(root = pathroot[path[v]], u)) {
            update(path[v], 0, pathpos[v], d);
            v = parent[root];
        }
        update(path[u], min(pathpos[u], pathpos[v]) + (int)VALUES_ON_EDGES,
                max(pathpos[u], pathpos[v]), d);
    }
};

int n, q, u, v, au, av, bu, bv, node_cnt;
vector <int> adj[N];

int main() {
    scanf("%d %d", &n, &q);
    adj[0].eb(1);
    adj[1].eb(0);
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &u, &v);
        adj[u].eb(v);
        adj[v].eb(u);
    }

    heavy_light <int> hld(n+1, adj);

    while (q--) {
        scanf("%d %d %d %d", &au, &av, &bu, &bv);
        hld.update(au, av, 1);
        printf("%d\n", hld.query(bu, bv));
        hld.update(au, av, -1);
    }

    return 0;
}

