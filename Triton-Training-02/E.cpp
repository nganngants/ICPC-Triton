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

string s, t;
int pos[N][133];

void solve ()
{
//    memset(pos,-1,sizeof pos);
    int n = sz(s), m = sz(t);
    if (n < m)
    {
        cout << "NO\n";
        return ;
    }
    if (n == m)
    {
        if (s == t) cout << "YES\n";
        else cout << "NO\n";
        return;
    }
    for (int c='a';c<='z';++c) pos[n][c] = -1;
    for (int i=n-1;i>=0;--i)
        for (int c='a';c<='z';++c)
        if (s[i] == c) pos[i][c] = i;
        else pos[i][c] = pos[i + 1][c];
    int i = (n - m) % 2;
    int k = 0;
    while (k < m && i < n)
    {
        int j = pos[i][t[k]];
        while ((j - i) % 2 && j != -1)
        {
//            cout << i << " " << j << '\n';
            j++;
            j = pos[j][t[k]];
        }
        if (j == -1)
        {
            cout << "NO\n";
            return;
        }
        k++;
        i = j + 1;
    }
    if (k == m) cout << "YES\n";
    else cout << "NO\n";
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
        cin >> s >> t;
        solve();
    }
    return 0;
}
