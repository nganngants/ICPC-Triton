#include <bits/stdc++.h>
 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define mid ((l+r)>>1)
#define file "Traffic Lights"
 
using namespace std;
 
const ll oo = 2e18;
const int N = 100003;
typedef pair<int,int> ii;
 
multiset <int> pos, len;
int n,m;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    freopen(file".inp","r",stdin);
//    freopen(file".out","w",stdout);
    cin >> n >> m;
    pos.insert(0); pos.insert(n); len.insert(n);
    while (m--)
    {
        int x;
        cin >> x;
        pos.insert(x);
        int a = *prev(pos.find(x)), b = *next(pos.find(x));
        len.erase(len.find(b - a));
        len.insert(b-x); len.insert(x-a);
        cout << *len.rbegin() << " ";
    }
    return 0;
}