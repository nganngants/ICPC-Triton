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
const int base = 311;
const ll oo = 2e18;
const int N = 2*100001;
const ll mod = 1e9 + 7;
typedef pair<ll,ll> ii;
typedef pair<ll,pair<ll,ll>> edge;
#define Speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
bool f[mod];
ll n,m,d,hashT,x;
int main()
{
    Speed;
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    cin>>n>>m>>d;
    for(int i=1;i<=n;i++)
    {
        hashT=0;
        for(int i=1;i<=d+1;i++)
        {
            cin>>x;
            hashT=((hashT * base + x+1) % mod);
        }
        f[hashT]=true;
    }
    for(int i=1;i<=m;i++)
    {
        hashT=0;
        for(int i=1;i<=d+1;i++)
        {
            cin>>x;
            hashT=((hashT * base + x+1) % mod);
        }
        if(f[hashT]) cout<<"BAD";
        else cout<<"GOOD";
        cout<<"\n";
    }
}
