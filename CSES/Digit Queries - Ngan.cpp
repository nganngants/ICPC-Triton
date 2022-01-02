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

ll memo[N],k,n;

void setup()
{
    ll cur = 9;
    for (int i=1;;++i)
    {
        memo[i] = cur * i;
        memo[i] += memo[i - 1];
        cur *= 10;
        if (memo[i] > 1e18)
        {
            n = i;
            break;
        }
    }
}

void solve ()
{
    int pos = lower_bound(memo+1,memo+n+1,k) - memo;
    ll fir = 1;
    for (int i=2;i<=pos;++i) fir *= 10;
    fir += (k - memo[pos - 1]) / pos - 1;
    int vts = (k - memo[pos - 1]) % pos;
    if (vts == 0) cout << fir % 10 << '\n';
    else
    {
        fir++;
        for (int i=1;i<=pos - vts;++i) fir /= 10;
        cout << fir % 10 << '\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen (file".inp","r",stdin);
//    freopen (file".out","w",stdout);
    setup();
    int test;
    cin >> test;
    while (test--)
    {
        cin >> k;
        solve();
    }
    return 0;
}
// 1 134
