#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pb push_back
#define mp make_pair
#define sz(a) (int)a.size()
#define fu(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)

using namespace std;
using namespace __gnu_pbds;

const ll oo = 2e18;
const int N = 250003;
const ll mod = 1e9 + 7;
typedef pair<int, int> pii;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> OST;

int n, a[N];

OST bit[N];

void insert(int x, int y)
{
	for(int i = x; i < N; i += i & -i)
		bit[i].insert(mp(y, x));
}

void remove(int x, int y)
{
	for(int i = x; i < N; i += i & -i)
		bit[i].erase(mp(y, x));
}

int query(int x, int y)
{
	int ans = 0;
	for(int i = x; i > 0; i -= i & -i)
		ans += bit[i].order_of_key(mp(y+1, 0));
	return ans;
}

ll getSum (int x, int y, int xx, int yy)
{
    if (xx < 1 || yy < 1) return 0;
    return query(xx, yy) + query(x - 1, y - 1)
            - query(xx, y - 1) - query(x - 1, yy);
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    freopen(file".inp","r",stdin);
//    freopen(file".out","w",stdout);
    cin >> n;
    //bit.resize(n + 1);
    fu(i,1,n) cin >> a[i];
    fu(i,1,n / 2)
        swap(a[i], a[n - i + 1]);
    ll cur = 0;
    fu(i,1,n)
    {
        cur += getSum(1, 1, i - 1, a[i] - 1);
        insert(i, a[i]);
    }
    int q;
    cin >> q;
    fu(i,1,q)
    {
        int x, y;
        cin >> x >> y;
        x = n - x + 1;
        cur -= (getSum(1, 1, x - 1, a[x] - 1) + getSum(x + 1, a[x] + 1, n, 50000));
        remove(x, a[x]);
        insert(x, y);
        a[x] = y;
        cur += (getSum(1, 1, x - 1, y - 1) + getSum(x + 1, y + 1, n, 50000));
        cout << cur << '\n';
    }

    return 0;
}
 
