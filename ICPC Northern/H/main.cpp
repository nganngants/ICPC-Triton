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
typedef pair<int,int> ii;

int n, x, res = 0;
int d[N];

bool check()
{
    vector <int> memo;
    for (int i=1;i<=2*n;++i)
        if (d[i] == 1) memo.pb(i);
    for (int i=0;i<sz(memo);++i)
        for (int j=i+1;j<sz(memo);++j)
        if (j - i == 1 || j - i == n + x) return false;
    return true;
}

void solve (int i)
{
    if (i == 2 * n + 1)
    {
        res += check();
        return;
    }
    for (int j=0;j<=1;++j)
    {
        d[i] = j;
        solve(i + 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen (file".inp","r",stdin);
//    freopen (file".out","w",stdout);
    cin >> n >> x;
    solve(1);
    cout << res;
    return 0;
}
