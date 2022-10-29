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
const int N = 300003;
const int M = 1000003;
const ll mod = 1e9 + 7;
typedef pair<ll, ll> ii;

int par[N][20];
vector <int> a[N];
int n, h[N];

void prepareLCA()
{
    fu(k,1,19)
        fu(i, 1, n)
        if (par[i][k - 1] != -1)
            par[i][k] = par[par[i][k - 1]][k - 1];
}

int LCA (int u, int v)
{
    if (h[u] < h[v]) swap(u, v);
    fd(k,19, 0)
        if (h[u] - (1 << k) >= h[v])
            u = par[u][k];
    if (u == v) return u;

    fd(k, 19, 0)
        if (par[u][k] != par[v][k] && par[u][k] != -1 && par[v][k] != -1)
            u = par[u][k],
            v = par[v][k];
    return par[u][0];
}

void dfs (int u, int p)
{
    h[u] = h[p] + 1;
    par[u][0] = p;
    for (auto v : a[u])
        if (v != p)
        dfs(v, u);
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    freopen(file".inp","r",stdin);
//    freopen(file".out","w",stdout);

    return 0;
}
