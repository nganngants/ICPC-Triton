#include <bits/stdc++.h>
 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define mid ((l+r)>>1)
#define file "Playlist"
 
using namespace std;
 
const ll oo = 2e18;
const int N = 200003;
typedef pair<int,int> ii;
 
int n, pre[N], res = 0;
ll a[N];
vector <ll> A;
 
void compress ()
{
    sort(A.begin(),A.end());
    int len = unique(A.begin(),A.end()) - A.begin();
    A.resize(len);
    for (int i=1;i<=n;++i) a[i] = lower_bound(A.begin(),A.end(),a[i]) - A.begin() + 1;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    ifstream cin (file".INP");
//    ofstream cout (file".OUT");
    cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i], A.pb(a[i]);
    compress();
    int cnt = 1;
    int l = 1;
    pre[a[1]] = 1;
    for (int r=2;r<=n;++r)
        if (pre[a[r]] < l) cnt++, pre[a[r]] = r;
        else
        {
            res = max(res,cnt);
            l = pre[a[r]] + 1;
            pre[a[r]] = r;
            cnt = r - l + 1;
        }
    res = max(res,cnt);
    cout << res;
    return 0;
}