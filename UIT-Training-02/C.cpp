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
const int N = 1003;
const ll mod = 1e9 + 7;
typedef pair<int,int> ii;

int n,m;
ll res;
ii a[N];
vector <ii> seg;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen (file".inp","r",stdin);
//    freopen (file".out","w",stdout);
    cin >> n >> m;
    res = n + 1;
    for (int i=1;i<=m;++i)
    {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a+1,a+m+1);
    seg.pb(a[1]);
    for (int i=2;i<=m;++i)
    {
        ii pre = seg.back();
        seg.pop_back();
        if (pre.se < a[i].fi)
        {
            seg.pb(pre);
            seg.pb(a[i]);
        }
        else
        {
//            cout << pre.fi << " " << pre.se << " " << a[i].fi << " " << a[i].se << '\n';
            seg.pb({pre.fi,max(pre.se,a[i].se)});
        }
    }
    for (auto it : seg)
    {
//        cout << it.fi << " " << it.se << '\n';
        res += (it.se - it.fi) * 2;
    }
    cout << res;
    return 0;
}
