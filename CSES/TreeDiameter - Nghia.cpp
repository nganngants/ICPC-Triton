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
int n,dinh,maxc=-1,x,y;
bool Visit[N];
vector<int> ke[N];
void finddinh(int s,int cost)
{
    Visit[s]=true;
    if(cost>maxc)
    {
        dinh=s;
        maxc=cost;
    }
    for(auto t:ke[s])
    {
        if(!Visit[t])
        {
            finddinh(t,cost+1);
        }
    }
}
void dfs(int s,int cost)
{
    Visit[s]=false;
    if(cost>maxc)
    {
        dinh=s;
        maxc=cost;
    }
    for(auto t:ke[s])
    {
        if(Visit[t])
        {
            dfs(t,cost+1);
        }
    }
}
int main()
{
    Speed;
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        cin>>x>>y;
        ke[x].pb(y);
        ke[y].pb(x);
    }
    finddinh(1,0);
    maxc=-1;
    dfs(dinh,0);
    cout<<maxc;
}
