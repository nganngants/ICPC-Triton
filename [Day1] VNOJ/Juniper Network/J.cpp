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
int n,p[N],q[N],d;
int f[N];
int main()
{
    Speed;
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i]>>q[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(!f[p[i]]&&!f[q[i]])
        {
            d++;
        }
        for(int j=1;j<=n;j++)
            if(i!=j)
            {
                if(p[j]==p[i] || p[j]==q[i] || q[j]==p[i] || q[j]==q[i])
                {
                    f[p[j]]=true;
                    f[q[j]]=true;
                }
            }
        f[p[i]]=true;
        f[q[i]]=true;
    }
    cout<<d;
}
