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
const int N = 100003;
const ll mod = 1e9 + 7;
typedef pair<int,int> ii;

ll st[4*N], lt[4*N], rt[4*N];
int n, test;

ll sum (ll A, ll B, int len)
{
    return (B * len + len * (len - 1) * A / 2) % mod;
}

void upd (int id, int l, int r, int xl, int xr, ll A, ll B)
{
    if (xr < l || xl > r) return;
    if (xl <= l && xr >= r)
    {
        ll _B = B + (l - xl) * A;
        st[id] += sum(A,_B, r - l + 1);
        lt[id] += A;
        rt[id] += _B;
        return;
    }
    if (lt[id] || rt[id])
    {
        upd(id<<1,l,mid,l,mid,lt[id],rt[id]);
        upd(id<<1|1,mid+1,r,mid+1,r,lt[id],rt[id] + (mid + 1 - l) * lt[id]);
        lt[id] = rt[id] = 0;
    }
    upd(id<<1,l,mid,xl,xr,A,B);
    upd(id<<1|1,mid+1,r,xl,xr,A,B);
    st[id] = (st[id<<1] + st[id<<1|1]) % mod;
}

ll getval (int id, int l, int r, int xl, int xr)
{
    if (xr < l || xl > r) return 0;
    if (xl <= l && xr >= r) return st[id];
    if (lt[id] || rt[id])
    {
        upd(id<<1,l,mid,l,mid,lt[id],rt[id]);
        upd(id<<1|1,mid+1,r,mid+1,r,lt[id],rt[id] + (mid - l + 1) * lt[id]);
        lt[id] = rt[id] = 0;
    }
    return (getval(id<<1,l,mid,xl,xr) + getval(id<<1|1,mid+1,r,xl,xr)) % mod;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen (file".inp","r",stdin);
//    freopen (file".out","w",stdout);
    cin >> n >> test;
    while (test--)
    {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1)
        {
            int A, B;
            cin >> A >> B;
            upd(1,1,n,l,r,A,B);
        }
        else cout << getval(1,1,n,l,r) % mod << '\n';
    }
    return 0;
}
