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
string solve()
{
    string n;
    int k;
    cin>>n>>k;

    while(true)
    {
       set<char> s;
       for (auto x:n)
       {
           s.insert(x);
       }
       if(sz(s) <= k) return n;
       s.clear();
       int ptr = 0;
       while(ptr<sz(n))
       {
            s.insert(n[ptr]);
            if(sz(s)>k)
            {
                while(n[ptr] == '9')
                    ptr--;
                n[ptr]++;
                for(int i=ptr+1;i<sz(n);i++)
                    n[i] = '0';
                break;
            }
            ptr++;
       }
    }
}
int main()
{
    Speed;
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        cout<<solve()<<"\n";
    }
}
