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
int n,p,con[N];
vector<int> ke[N];
void dfs(int s)
{
    for(auto t:ke[s])
    {
        dfs(t);
        con[s]+=con[t]+1;
    }
}
int main()
{
    Speed;
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        //ke[1].pb(i);
        cin>>p;
        ke[p].pb(i);
    }
    dfs(1);
    for(int i=1;i<=n;i++)
    {
        cout<<con[i]<<" ";
    }
}
