#include <bits/stdc++.h>

#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define mid ((l+r)>>1)
#define sz(a) (int)a.size()
#define file ""

using namespace std;

const ll oo = 2e18;
const int N = 50003;
const ll mod = 1e9 + 7;
typedef pair<int,int> ii;

struct edge
{
    int u, v, d;
    bool operator < (const edge &x)
    {
        return d < x.d;
    }
}a[N];

int n, m, r[N], p[N];
bool flag[N];
vector <int> used;

int findPar(int x)
{
    if (p[x] == x) return x;
    return p[x] = findPar(p[x]);
}

bool join (int u, int v)
{
    u = findPar(u);
    v = findPar(v);
    if (u == v) return false;
    if (r[u] == r[v]) r[u]++;
    if (r[u] > r[v]) p[v] = u;
    else p[u] = v;
    return true;
}

int spanning (bool build)
{
    for (int i=1;i<=n;++i) p[i] = i, r[i] = 1;
    int sum = 0, cnt = 0;
    for (int i=1;i<=m;++i)
    {
        if (flag[i]) continue;
        edge it = a[i];
        bool ok = join(it.u,it.v);
//        if (build) cout << it.u << " " << it.v << " " << it.d << " " << ok << '\n';
        if (ok)
        {
            sum += it.d;
            cnt++;
            if (build) used.pb(i);
        }
    }
    if (cnt < n - 1) return -1;
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen (file".inp","r",stdin);
//    freopen (file".out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=m;++i)
    {
        cin >> a[i].u >> a[i].v >> a[i].d;
    }
    sort(a+1,a+m+1);
    int minimum = spanning(1);
//    for (auto it : used) cout << a[it].u << " " << a[it].v << " " << a[it].d << '\n';
    int cnt= 0, sum = 0;
    for (auto it : used)
    {
        flag[it] = 1;
        int nm = spanning(0);
        if (nm != minimum)
        {
            cnt++;
            sum += a[it].d;
        }
        flag[it] = 0;
    }
    cout << cnt << " " << sum << '\n';
    return 0;
}
