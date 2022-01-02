#include <bits/stdc++.h>
 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define file "Factory Machines"
 
using namespace std;
 
const ll oo = 2e18 + 13;
const int N = 200003;
typedef pair<int,int> ii;
 
int n;
ll t, a[N],res;
 
bool check(ll mid)
{
    ll cnt = 0;
    for (int i=1;i<=n;++i)
    {
        cnt += (mid / a[i]);
        if (cnt >= t) break;
    }
//    cout << "check: " << cnt << '\n';
    return (cnt >= t);
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    freopen(file".inp","r",stdin);
//    freopen(file".out","w",stdout);
    cin >> n >> t;
    for (int i=1;i<=n;++i) cin >> a[i];
    ll l = 0, r = oo, mid = (l + r) >> 1;
    while (l != mid && r != mid)
    {
//        cout << mid << '\n';
        if (check(mid)) res = mid, r = mid;
        else l = mid;
        mid = (l + r) >> 1;
    }
    cout << res;
    return 0;
}