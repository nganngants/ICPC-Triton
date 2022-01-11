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
const int N = 2*100001;
const ll mod = 1e9 + 7;
typedef pair<ll,ll> ii;
typedef pair<ll,pair<ll,ll>> edge;
#define Speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
ll p[N],n,x,k,f[N][21],t;
vector<ll> ke[N];
void dfs(int s,int p)
{
    f[s][0]=p;
    //p[s]=t;
    for(auto t:ke[s])
    if(t != p)
    {
        dfs(t,s);
    }

}
void LCA()
{
    for(int j=1; 1<<j <= n; j++)
    {
        for(int i=1;i<=n;i++)
            f[i][j]=f[f[i][j-1]][j-1];
    }
}
int main()
{
    Speed;
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    cin>>n>>t;
    for(int i=2;i<=n;i++)
    {
        cin>>x;
        ke[x].pb(i);
        ke[i].pb(x);
    }
    dfs(1,0);
    LCA();
    while(t--)
    {
        cin>>x>>k;
        for(int i=0;i<=20;i++)
            if((k & (1 << i))) x=f[x][i];
        if(x==0) cout<<-1;
        else cout<<x;
        cout<<"\n";
    }
}
