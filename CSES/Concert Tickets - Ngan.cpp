#include <bits/stdc++.h>

#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define mid ((l+r)>>1)
#define sz(a) (int)a.size()
#define file "Concert Tickets"

using namespace std;

const ll oo = 2e18;
const int N = 100003;
typedef pair<int,int> ii;

int n,m,temp;
multiset <int> st;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen (file".inp","r",stdin);
    freopen (file".out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;++i)
    {
        cin >> temp;
        st.insert(temp);
    }
    for (int i=1;i<=m;++i)
    {
        cin >> temp;
        auto it = st.upper_bound(temp);
        if (it == st.begin()) cout << -1 << '\n';
        else
        {
            cout << *prev(it) << '\n';
            st.erase(prev(it));
        }
    }
    return 0;
}
