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

int n, m, d;
map <string, bool> c;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen (file".inp","r",stdin);
//    freopen (file".out","w",stdout);
    cin >> n >> m >> d;
    for (int i=1;i<=n;++i)
    {
        string inp = "";
        for (int j=1;j<=d+1;++j)
        {
            int x;
            cin >> x;
            inp += char(x + '0');
        }
        c[inp] = true;
    }
    for (int i=1;i<=m;++i)
    {
        string inp = "";
        for (int j=1;j<=d+1;++j)
        {
            int x;
            cin >> x;
            inp += char(x + '0');
        }
        if (c[inp]) cout << "BAD\n";
        else cout << "GOOD\n";
    }

    return 0;
}
