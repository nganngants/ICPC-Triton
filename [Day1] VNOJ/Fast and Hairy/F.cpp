#include <bits/stdc++.h>

#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define mid ((l+r)>>1)
#define sz(a) (int)a.size()
#define file "F"

using namespace std;

const ll oo = 1e9;
const int N = 10003;
const ll mod = 1e9 + 7;
typedef pair<int,int> ii;

int n;
ll u, v;
ll a[N], res, sum;
int cnt[103];
int f[N*200];

bool Try (ll cur, ll valu, ll valv, int c[])
{
//    cout << cur << " " << valu << " " << valv << '\n';
    if (cur <= valu && sum - cur <= valv) return true;
    if (f[cur] == 1) return true;
    if (f[cur] == -1) return false;
    for (int i=1;i<=100;++i)
        if (c[i] < cnt[i])
        {
            c[i]++;
            f[cur] = (Try(cur+i,valu,valv,c) ? 1 : 0);
            if (f[cur]) return true;
            c[i]--;
        }
    f[cur] = -1;
    return false;
}

bool check (ll t)
{
//    cout << t << '\n';
    ll _u = t * u, _v = t * v;
    if (_u + _v < sum) return false;
    int c[103];
    memset(f,0,sizeof f);
    memset(c,0,sizeof c);
    if (_u > _v) swap(_u,_v);
    return Try(0,_u,_v,c);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen (file".inp","r",stdin);
//    freopen (file".out","w",stdout);
    int test;
    cin >> test;
    while (test--)
    {
        cin >> n >> u >> v;
        sum = 0;
        memset(cnt,0,sizeof cnt);
        for (int i=1;i<=n;++i) cin >> a[i], sum += a[i], cnt[a[i]]++;
        res = sum / min(u,v) + (res % min(u,v) != 0);
        ll l = 0, r = sum / max(u,v) + 2;
        while (mid != l && mid != r)
        {
            if (check(mid))
            {
                res = mid;
                r = mid;
            }
            else l = mid;
        }
        cout << res << '\n';
    }
    return 0;
}
/*
1
1 2 2
1
*/
