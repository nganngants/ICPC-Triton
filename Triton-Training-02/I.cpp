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
const int N = 500003;
const ll mod = 1e9 + 7;
typedef pair<int,int> ii;

int n;
ll sum, a[N], res = 0;
map <ll,ll> m;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen (file".inp","r",stdin);
//    freopen (file".out","w",stdout);
    cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i], a[i] += a[i - 1];
    sum = a[n];
    if (sum % 3 || n < 3)
    {
        cout << 0;
        return 0;
    }
    sum /= 3;
    for (int i=n;i>=1;--i)
    {
        if (a[i] == sum)
        {
//            cout << i << " " << sum + a[i] << " " << m[sum + a[i]] << '\n';
            res += m[sum + a[i]];
        }
        if (i < n) m[a[i]]++;
    }
    cout << res;
    return 0;
}
