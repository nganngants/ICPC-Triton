#include <bits/stdc++.h>

#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define mid ((l+r)>>1)
#define sz(a) (int)a.size()
#define file ""
#define maxN 5000001
using namespace std;

const ll oo = 2e18;
const int N = 2*100001;
const ll mod = 1e9 + 7;
typedef pair<ll,ll> ii;
typedef pair<ll,pair<ll,ll>> edge;
#define Speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
ll t,n,e,a[N],ans;
bool f[maxN];
ll nto[N],one[N],res[N];
int main()
{
    Speed;
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    f[0]=f[1]=true;
    for(int i=2; i<=sqrt(maxN); i++)
        if(!f[i])
        {
            ll j = i*i;
            while(j<=maxN)
            {
                f[j]=true;
                j+=i;
            }
        }
    cin>>t;
    while(t--)
    {
        cin>>n>>e;

        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
            nto[i]=0;
            one[i]=0;
            res[i]=0;
        }
        ans=0;
        for(int i=n; i>=1; i--)
        {
            if(i+e<=n)
            {
                if(!f[a[i]])
                {
                    res[i]+=one[i+e];
                }
                else if(a[i]==1)
                {
                    if(a[i+e]==1)
                        res[i]=res[i+e];
                    if(!f[a[i+e]])
                        res[i]=res[i+e]+1;
                    //if(!f[a[i+e]] && res[i]==0) res[i]++;
                }
                ans+=res[i];
            }
            if(a[i]==1)
            {
                if(a[i+e]==1 && i+e<=n)
                    one[i]=one[i+e]+1;
                else
                    one[i]=1;
            }
        }
//        for(int i=1;i<=n;i++)
//            cout<<res[i]<<" ";cout<<"\n";
        cout<<ans<<"\n";
    }
}







