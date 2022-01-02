#include <bits/stdc++.h>
 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define mid ((l+r)>>1)
#define file "Room Allocation"
 
using namespace std;
 
const ll oo = 2e18;
const int N = 200003;
typedef pair<int,int> ii;
typedef pair<ii,int> pii;
 
priority_queue <ii,vector<ii>,greater<ii> > q;
int n,num=0,res[N];
pii a[N];
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    freopen(file".inp","r",stdin);
//    freopen(file".out","w",stdout);
    cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i].fi.fi >> a[i].fi.se, a[i].se = i;
    sort(a+1,a+n+1);
    for (int i=1;i<=n;++i)
    {
        ii temp = a[i].fi;
        int pos = a[i].se;
//        cout << "+) " << i << '\n';
//        cout << temp.fi << " " << temp.se << " " << pos << '\n';
//        if (q.size()) cout << q.top().fi << " " << q.top().se << '\n';
        if (q.empty() || q.top().fi >= temp.fi)
        {
            num++;
            res[pos] = num;
            q.push({temp.se,num});
        }
        else
        {
            res[pos] = q.top().se;
            q.pop();
            q.push({temp.se,res[pos]});
        }
    }
    cout << num << '\n';
    for (int i=1;i<=n;++i) cout << res[i] << " ";
    return 0;
}