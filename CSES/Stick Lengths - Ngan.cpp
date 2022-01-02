#include <bits/stdc++.h>

#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define mid ((l+r)>>1)
#define sz(a) (int)a.size()
#define file "Stick Lengths"

using namespace std;

const ll oo = 2e18;
const int N = 200003;
typedef pair<int,int> ii;

int n, a[N];
ll res = 0;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen (file".inp","r",stdin);
//    freopen (file".out","w",stdout);
    cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i];
    sort(a+1,a+n+1);
    int x = n / 2;
    if (n % 2 == 1) x++;
    for (int i=1;i<=n;++i) res += abs(a[i] - a[x]);
    cout << res;
    return 0;
}
