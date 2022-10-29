#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define fi first
#define se second
#define pb push_back
#define mid ((l+r)>>1)
#define sz(a) (int)a.size()
#define fu(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define bit(x,i) (int)((x>>i)&1)
#define file ""

using namespace std;
using namespace __gnu_pbds;
typedef tree<
    int,
    null_type,
    ///less -> set, less_equal -> multiset
    less_equal<int>,
    rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

const ll oo = 2e18;
const int N = 300003;
const int M = 1000003;
const ll mod = 1e9 + 7;
typedef pair<ll, ll> ii;

template <class T>
class segtree
{
private:
    vector <T> st;
    int def;
public:
    segtree(int n = 1, T def = 0)
    {
        this->def = def;
        st = vector <T> (4 * n + 4, def);
    }

    T calval (T l, T r)
    {
        /// edit the type of segtree here
        return l + r;
    }
    void upd (int id, int l, int r, int pos, T val)
    {
        if (pos < l || pos > r) return;
        if (l == r)
        {
            st[id] = val;
            return;
        }
        upd(id << 1, l, mid, pos, val);
        upd(id << 1 | 1, mid + 1, r, pos, val);
        st[id] = this->calval(st[id << 1], st[id << 1 | 1]);
    }

    T getval (int id, int l, int r, int xl, int xr)
    {
        if (xl > r || xr < l) return def;
        if (xl <= l && xr >= r) return st[id];
        return calval(getval(id << 1, l, mid, xl, xr), getval(id << 1 | 1, mid + 1, r, xl, xr));
    }
};

int n, q;
segtree <ll> st;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    freopen(file".inp","r",stdin);
//    freopen(file".out","w",stdout);
    cin >> n >> q;
    st = segtree<ll> (n, 0);
    fu(i,1,n)
    {
        ll x;
        cin >> x;
        st.upd(1,1,n,i,x);
    }
    while (q--)
    {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1)
        {
            st.upd(1,1,n,l,r);
        }
        else cout << st.getval(1,1,n,l,r) << '\n';
    }
    return 0;
}
