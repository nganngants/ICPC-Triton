#include <bits/stdc++.h>
 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define mid ((l+r)>>1)
#define file "Maximum Subarray Sum"
 
using namespace std;
 
const ll oo = 2e9;
const int N = 200003;
typedef pair<int,int> ii;
 
int n;
ll res, a[N];
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    ifstream cin (file".INP");
//    ofstream cout (file".OUT");
    cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i], a[i] += a[i-1];
    res = a[1];
    ll pre = min(a[1],(ll)0);
    for (int i=2;i<=n;++i) res = max(res,a[i] - pre), pre = min(pre,a[i]);
    cout << res;
    return 0;
}