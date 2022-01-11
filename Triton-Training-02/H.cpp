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

const ll oo = 1e8;
const int N = 200003;
const ll mod = 1e9 + 7;
typedef pair<int,int> ii;

int n, m, a[N], b[N];
vector <int> one, two;
ll sum = 0;

void enter ()
{
    cin >> n >> m;
    one.clear();
    two.clear();
    sum = 0;
    for (int i=1;i<=n;++i) cin >> a[i], sum += a[i];
    for (int i=1;i<=n;++i)
    {
        cin >> b[i];
        if (b[i] == 1) one.pb(a[i]);
        else two.pb(a[i]);
    }
    sort(one.rbegin(),one.rend());
    sort(two.rbegin(),two.rend());
//    for (auto i : one) cout << i << " ";
//    cout << '\n';
//    for (auto i : two) cout << i << " ";
//    cout << '\n';
}

void solve ()
{
    ll sumOne = 0, sumTwo = 0;
    for (auto it : two) sumTwo += it;
    int j = sz(two) - 1;
    int res = oo;
    for (int i=0;i<=sz(one);++i)
    {
        while (j >= 0 && sumOne + sumTwo - two[j] >= m)
        {
            sumTwo -= two[j];
            j--;
        }
        if (sumOne + sumTwo >= m) res = min(res,i+(j+1) * 2);
//        cout << i << " " << j << " " << sumOne << " " << sumTwo << '\n';
        if (i < sz(one)) sumOne += one[i];
    }
    if (res == oo) cout << -1 << '\n'; else cout << res << '\n';
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen (file".inp","r",stdin);
//    freopen (file".out","w",stdout);
    int test;
    cin >> test;
    while (test--)
    {
        enter();
        solve();
    }
    return 0;
}
/*
1
5 7
5 3 2 1 4
2 1 1 2 1
*/
