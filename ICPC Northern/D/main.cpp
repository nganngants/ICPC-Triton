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
const int N = 1000003;
const ll mod = 1e9 + 7;
typedef pair<int,int> ii;

int n;
string s;
int dp[N];

void solve()
{
    memset(dp,0,sizeof dp);
    n = sz(s) - 1;
    dp[n] = (s[n] == '1');
    for (int i=n-1;i>=0;--i)
    {
        if (s[i]== '0') dp[i] = min(dp[i + 1], dp[i + 2]);
        else
        {
            if (s[i + 1] == '1') dp[i] = dp[i + 1] + 1;
            else dp[i] = dp[i + 2];
        }
    }
//    for (int i=0;i<=n;++i) cout << dp[i] << " ";
    cout << dp[0] << '\n';

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
        cin >> s;
        solve();
    }
    return 0;
}
/*
2
1101010111
101
*/
