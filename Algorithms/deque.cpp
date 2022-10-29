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

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    freopen(file".inp","r",stdin);
//    freopen(file".out","w",stdout);
    deque <int> dq;

    /* Làm rỗng deque */
    while (dq.size()) dq.pop_front();

    /* Duyệt lần lượt các phần tử từ 1 đến N */
    for (int i = 1; i <= N; ++i) {
        /* Loại bỏ các phần tử có giá trị lớn hơn hoặc bằng A[i] */
        while (dq.size() && A[dq.back()] >= A[i]) dq.pop_back();

        /* Đẩy phần tử i vào queue */
        dq.push_back(i);

        /* Nếu phần tử đầu tiên trong deque nằm ngoài khoảng tính
           thì ta sẽ loại bỏ ra khỏi deque */
        if (dq.front() + k <= i) dq.pop_front();

        /* minRange[i] là giá trị nhỏ nhất trong đoạn [i – k + 1 … i] */
        if (i >= k) minRange[i] = A[dq.front()];
    }
    return 0;
}
