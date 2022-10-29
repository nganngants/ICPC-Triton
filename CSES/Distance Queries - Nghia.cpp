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
ll p[N],n,u,v,f[N][21],t,h[N];
vector<ll> ke[N];
void dfs(int s,int par, int height)
{
    f[s][0]=par;
    h[s]=height;
    p[s]=par;
    for(auto t:ke[s])
    if(t != par)
    {
        dfs(t,s,height+1);
    }

}
void prepareLCA()
{
    for(int j=1; 1<<j <= n; j++)
    {
        for(int i=1;i<=n;i++)
            f[i][j]=f[f[i][j-1]][j-1];
    }
}
int LCA_calc(int x,int y)
{
    if(h[x]<h[y]) swap(x,y);
    int l = log2(h[x]);
    //cout<<l<<"----\n";
    for(int i=l; i>=0; i--)
        if( h[x] - (1 << i) >= h[y])
            x=f[x][i];
    //cout<<x<<" "<<y<<"<-->\n";
    if(x == y) return x;
    l=log2(h[x]);
    //cout<<l<<"----\n";
    for(int i=l;i>=0;i--)
        if(f[x][i]!=f[y][i] && f[x][i]!=0)
        {
            x=f[x][i];
            y=f[y][i];
        }

    //cout<<x<<" "<<y<<"<-->\n";
    return p[x];
}
int main()
{
    Speed;
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    cin>>n>>t;
    for(int i=2;i<=n;i++)
    {
        cin>>u>>v;
        ke[u].pb(v);
        ke[v].pb(u);
    }
    dfs(1,0,0);
    prepareLCA();
    while(t--)
    {
        cin>>u>>v;
        cout<<h[u]+h[v]-2*h[LCA_calc(u,v)]<<"\n";
    }
}
