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
const int N = 100003;
const ll mod = 1e9 + 7;
typedef pair<vector <int>,int> ii;

int n, k, cnt[30];
vector<int> memo[N][30];


bool cmp (ii x, ii y)
{
    if (sz(x.fi) != sz(y.fi)) return sz(x.fi) < sz(y.fi);
    for (int i=0;i<sz(x.fi);++i)
        if (x.fi[i] > y.fi[i]) return false;
    return true;
}

bool ok(vector <int> x, vector <int> y)
{
    if (sz(x) != sz(y)) return false;
    for (int i=0;i<sz(x);++i)
        if (x[i] != y[i]) return false;
    return true;
}

bool solve (vector <int> proc, bool vis[])
{
//    for (auto i : proc) cout << i << ' ';
//    cout << '\n';
    if (sz(proc) <= 1) return true;

    vector <ii> mem;
    for (int j=0;j<26;++j)
        if (!vis[j] && cnt[j] >= sz(proc))
    {
        for (auto i : proc) if (sz(memo[i][j])) mem.pb({memo[i][j],i});
        if (sz(mem) == sz(proc)) {vis[j] = true;break;}
        mem.clear();
    }
//    for (auto i : mem) cout << i.fi << " " << i.se << '\n';;
//    cout <<"========================\n";
    if (sz(mem) != sz(proc)) return false;
    sort(mem.begin(),mem.end());
    vector <int> down;
    int i = 0, j = 0;
    bool res = true;
    while (i < sz(mem) && j < sz(mem))
    {
        bool dvis[30];
        for (int t=0;t<30;++t) dvis[t] = vis[t];
        while (j < sz(mem) && mem[j].fi == mem[i].fi) down.pb(mem[j++].se);
        i++;
        if (sz(down))
        {
            res &= solve(down,dvis);
            down.clear();
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen (file".inp","r",stdin);
//    freopen (file".out","w",stdout);
    cin >> n >> k;
    for (int i=1;i<=k;++i)
    {
        string t;
        cin >> t;
        for (int j=0;j<n;++j)
        {
            char x = t[j];
            memo[i][x - 'a'].pb(j);
        }
    }

    for (int j=0;j<26;++j)
        for (int i=1;i<=k;++i)
        {
            sort(memo[i][j].begin(),memo[i][j].end());
            if (sz(memo[i][j]) > 0) cnt[j]++;
        }

    vector <int> proc;
    bool vis[30];
    memset(vis,false,sizeof vis);
    for (int i=1;i<=k;++i) proc.pb(i);

    bool res = solve(proc,vis);
    if (res) cout << "YES"; else cout << "NO";
    return 0;
}
/*
6 4
taylor
karlie
catele
nagnln
thuong
*/
