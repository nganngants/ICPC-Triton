#include <bits/stdc++.h>
 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define mid ((l+r)>>1)
#define file "Towers"
 
using namespace std;
 
const ll oo = 2e18;
const int N = 200003;
typedef pair<int,int> ii;
 
int n,res = 0;
ll a[N];
map <ll,int> m;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    ifstream cin (file".INP");
//    ofstream cout (file".OUT");
    cin >> n;
    for (int i=1;i<=n;++i)
    {
        cin >> a[i];
        auto it = m.upper_bound(a[i]);
        if (it == m.end()) res++;
        else
        {
            m[it->fi]--;
            if (m[it->fi] == 0)
            m.erase(it);
        }
        m[a[i]]++;
    }
    cout << res;
    return 0;
}