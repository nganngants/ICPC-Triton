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
const int N = 1e6+1;
const ll mod = 1e9 + 7;
typedef pair<ll,ll> ii;
typedef pair<ll,pair<ll,ll>> edge;
#define Speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
ll x,p[10],n,dp[N],ans;
void day(int i)
{
    if(i==n) p[i]=0;
    for(int j=i;j<=n-1;j++)
    {
        p[j]=p[j+1];
    }
    return;
}
int main()
{
    Speed;
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    cin>>x>>n;
    for(int i=1;i<=n;i++)
    {cin>>p[i];
    }
    sort(p+1,p+n+1);
    for(int i=2;i<=n;i++)
    {
        while(p[i]==p[i-1]) {day(i);n--;}
    }
    //for(int i=1;i<=n;i++) cout<<p[i]<<" ";
    dp[0]=1;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=x;j++)
    {

            if(j-p[i]>=0)
        {
            dp[j]+=dp[j-p[i]];
        }
    }
    //for(int i=1;i<=x;i++) cout<<dp[i]<<" ";
    cout<<dp[x];
}
