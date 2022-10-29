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
ll n,q,Start[N],End[N],bit[N],val[N],timer=1,x,y,k;
vector<ll> ke[N];
ll getsum(int i)
{
    ll sum=0;
    for(;i>0;i-=(i & (-i)))
    {
        sum+=bit[i];
    }
    return sum;
}
void update(int i, ll value)
{
    for(;i<=n;i+=(i & (-i)))
    {
        bit[i]+=value;
    }
}
void dfs(int s, int par)
{
    Start[s]=timer;
    update(timer,val[s]);
    for(auto t:ke[s])
    if(t != par)
    {
        timer++;
        dfs(t,s);
    }
    End[s]=timer;
}

int main()
{
    Speed;
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>val[i];
    }
    for(int i=1;i<=n-1;i++)
    {
        cin>>x>>y;
        ke[x].pb(y);
        ke[y].pb(x);
    }
    dfs(1,0);
    while(q--)
    {
        cin>>k;
        if(k == 1)
        {
            cin>>x>>y;
            update(Start[x],-val[x]);
            val[x]=y;
            update(Start[x],y);
        }
        else
        {
            cin>>x;
            cout<<getsum(End[x])-getsum(Start[x]-1)<<"\n";
        }
    }
}
