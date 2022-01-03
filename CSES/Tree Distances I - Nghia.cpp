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
int a,b,dist[2][N],n,x,y,r;
vector<int> ke[N];
int fd(int s,int p, int d, int i)
{
    dist[i][s]=d;
    int opt = -1;
    for(auto t:ke[s])
    if(t!=p)
    {
        int x = fd(t,s,d+1,i);
        if(opt == -1 || dist[i][x] > dist[i][opt]) opt=x;
    }
    return opt == -1 ? s : opt;
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
    a = fd(1,1,0,0);//Tìm đỉnh a xa nhất từ x bất kỳ
    b = fd(a,a,0,0);// Tìm đỉnh b xa nhất từ a đồng thời tính dist từ a
    r = fd(b,b,0,1);// Tính dist từ b
    for(int i=1;i<=n;i++)
    {
        cout<<max(dist[0][i],dist[1][i])<<" ";
    }
}
