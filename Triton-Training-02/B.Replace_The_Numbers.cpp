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
const int N = 5*100001;
const ll mod = 1e9 + 7;
typedef pair<ll,ll> ii;
typedef pair<ll,pair<ll,ll>> edge;
#define Speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int p[N],q,t[N],x[N],y[N],a[N],n;
vector<int> res;

int main()
{
    Speed;
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    for(int i=1;i<=N;i++)p[i]=i;
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        cin>>t[i];
        if(t[i]==1)
        {
            cin>>x[i];
            n++;
        }
        else
        {
            cin>>x[i]>>y[i];
        }
    }
    int j=n;
    for(int i=q;i>=1;i--)
    {
        if(t[i]==1)
            a[j--]=p[x[i]];
        else
        {
            p[x[i]]=p[y[i]];
        }
    }
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
}
