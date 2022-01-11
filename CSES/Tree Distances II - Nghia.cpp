# include <bits/stdc++.h>

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
ll n,x,y,subtreeSize[N],subtreeAns[N],ans[N];
vector<ll> ke[N];
void dfs(int s, int p)
{
    ll node=1;
    ll res=0;
    for(auto t:ke[s])
    if(t != p)
    {
        dfs(t,s);
        node+=subtreeSize[t];
        res+=subtreeAns[t]+subtreeSize[t];
    }
    subtreeSize[s]=node;
    subtreeAns[s]=res;
}
void calc(int s, int p, ll par_ans)
{
     ans[s] = subtreeAns[s] + (par_ans + (n - subtreeSize[s]));
     for(auto t : ke[s])
     if(t != p)
     {
         calc(t, s, ans[s] - (subtreeAns[t] + subtreeSize[t]));
     }
}
int main()
{
    Speed;
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        ke[x].pb(y);
        ke[y].pb(x);
    }
    dfs(1,0);
    calc(1,0,0);
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
}
