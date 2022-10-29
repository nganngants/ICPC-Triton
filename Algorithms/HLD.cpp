/// Minimum spanning tree with each edge
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define fi first
#define se second
#define pb push_back
#define mid ((l+r)>>1)
#define sz(a) (int)a.size()
#define fu(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define bit(x,i) (int)((x>>i)&1)
#define file ""

using namespace std;
using namespace __gnu_pbds;
typedef tree<
    int,
    null_type,
    ///less -> set, less_equal -> multiset
    less_equal<int>,
    rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

const ll oo = 2e18;
const int N = 200003;
const int M = 1000003;
const ll mod = 1e9 + 7;
typedef pair<ll, ll> ii;

class edge
{
public:
    int u, v;
    ll w;
    int id;
    edge(int u, int v, ll w, int id): u(u), v(v), w(w), id(id) {}
    const bool operator < (const edge& e)
    {
        return w < e.w;
    }
};
class Node
{
public:
    int parent;
    int depth;
    int subtreeSize;
    int posInBase;
    int chainId;
    Node()
    {
        parent = -1;
        depth = subtreeSize = posInBase = chainId = 0;
    }
    const bool operator < (const Node& x)
    {
        return subtreeSize < x.subtreeSize;
    }
};

class segTree
{
private:
    vector <ll> st;
    vector <ll> val;
public:
    segTree (int n = 1)
    {
        st.resize(4 * n + 3);
        val.resize(n + 3);
    }

    void build (int id, int l, int r)
    {
        if (l == r)
        {
            st[id] = val[l];
            return;
        }
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        st[id] = max(st[id << 1], st[id << 1 | 1]);
    }

    ll getmax (int id, int l, int r, int xl, int xr)
    {
        if (xl > r || xr < l) return -1;
        if (xl <= l && xr >= r) return st[id];
        return max(getmax(id << 1, l, mid, xl, xr), getmax(id << 1 | 1, mid + 1, r, xl, xr));
    }

    ll& operator [] (int i)
    {
        return val[i];
    }
};

class DSU
{
private:
    vector <int> par, r;
public:
    DSU(int n = 0)
    {
        par.resize(n + 1);
        r.resize(n + 1);
        fu(i,1,n) par[i] = i, r[i] = 1;
    }

    int findPar (int u)
    {
        if (par[u] != u) par[u] = findPar(par[u]);
        return par[u];
    }
    bool join (int u, int v)
    {
        u = findPar(u);
        v = findPar(v);
        if (u == v) return false;
        if (r[u] == r[v]) r[u]++;
        if (r[u] < r[v]) par[u] = v;
        else par[v] = u;
        return true;
    }
};
vector <pair<ii, int> > a[N];
vector <edge> edges;
/// fi = weight, se = deeper end
ll e[N];
Node node[N];
segTree st;
int n, m;
int chainHead[N], noChains, nBase; ///for HLD
int par[N][20]; ///for LCA
bool used[N];
ll res[N];

void input()
{
    cin >> n >> m;
    st = segTree(n - 1);
    fu(i,1,m)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        e[i] = w;
        edges.pb(edge(u,v,w,i));
    }
}

void dfs(int u, int p)
{
//    cout << u << " " << p << '\n';
    par[u][0] = p;
    node[u].parent = p;
    node[u].depth = node[p].depth + 1;
    int subtreeSize = 1;

    for (auto it : a[u])
    {
        int w = it.fi.fi;
        int v = it.fi.se;
        int id = it.se;
        if (v == p) continue;
        dfs(v, u);
        subtreeSize += node[v].subtreeSize;
    }

    node[u].subtreeSize = subtreeSize;
}

void hld (int u, int edgeId)
{
//    cout << u << " " << edgeId << '\n';
    if (chainHead[noChains] == -1) chainHead[noChains] = u;
    node[u].chainId = noChains;
    node[u].posInBase = nBase++;
    st[node[u].posInBase] = e[edgeId];
    int heavyChild = 0;
    int childEdgeId = -1;
    for (auto it : a[u])
    {
        int v = it.fi.se;
        if (v == node[u].parent) continue;
        if (node[heavyChild] < node[v])
        {
            heavyChild = v;
            childEdgeId = it.se;
        }
    }

    if (heavyChild) hld(heavyChild, childEdgeId);

    for (auto it : a[u])
    {
        int v = it.fi.se;
        if (v == node[u].parent) continue;
        if (v != heavyChild)
        {
            noChains++;
            hld(v, it.se);
        }
    }
}

void prepareLCA()
{
    fu(k,1,19)
        fu(i, 1, n)
        if (par[i][k - 1] != -1)
            par[i][k] = par[par[i][k - 1]][k - 1];
}

int LCA (int u, int v)
{
    if (node[u].depth < node[v].depth) swap(u, v);
    fd(k,19, 0)
        if (node[u].depth - (1 << k) >= node[v].depth)
            u = par[u][k];
    if (u == v) return u;

    fd(k, 19, 0)
        if (par[u][k] != par[v][k] && par[u][k] != -1 && par[v][k] != -1)
            u = par[u][k],
            v = par[v][k];
    return par[u][0];
}

ll crawl (int u, int v)
{
    int cu, cv = node[v].chainId;
    ll ans = 0;
    while (u != v)
    {
        cu = node[u].chainId;
        if (cu == cv)
        {
            ans = max(ans, st.getmax(1,1,n - 1, node[v].posInBase + 1, node[u].posInBase));
            u = v;
        }
        else
        {
            int head = chainHead[cu];
            ans = max(ans, st.getmax(1,1,n - 1, node[head].posInBase, node[u].posInBase));
            u = node[head].parent;
        }
    }
    return ans;
}
/// max edge from u to v
ll query (int u, int v)
{
    int lca = LCA(u, v);
    return max(crawl(u, lca), crawl(v, lca));
}

ll findMST ()
{
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    ll ans = 0;
    for (auto e : edges)
    {
        if (dsu.join(e.u, e.v))
        {
            ans += e.w, used[e.id] = true;
            a[e.u].pb({{e.w, e.v}, e.id});
            a[e.v].pb({{e.w, e.u}, e.id});
//            cout << e.id << '\n';
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    freopen(file".inp","r",stdin);
//    freopen(file".out","w",stdout);
    input();
    if (!m) return 0;
    memset(par, -1, sizeof par);
    ll mst = findMST();
    dfs(1, 0);

    prepareLCA();
    memset(chainHead, -1, sizeof chainHead);
    noChains = 1; nBase = 0;
    /// fixed root = 1;
    hld(1, n);
    st.build(1,1,n - 1);
//
    for (auto e : edges)
    {
        if (used[e.id]) res[e.id] = mst;
        else
        {
            ll maxEdge = query(e.u, e.v);
            res[e.id] = mst - maxEdge + e.w;
        }
    }
    fu(i,1,m) cout << res[i] << '\n';
    return 0;
}
 
