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

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    freopen(file".inp","r",stdin);
//    freopen(file".out","w",stdout);

    return 0;
}
