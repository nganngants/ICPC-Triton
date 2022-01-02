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
const int N = 5003;
const ll mod = 1e9 + 7;
typedef pair<int,int> ii;

string s;
int q;
ll f[N][N];
bool pa[N][N];

ll solve (int i, int j)
{
    if (f[i][j] != -1)
    {
        return f[i][j];
    }
    if (i > j) return 0;
    ll res = solve(i,j-1) + solve(i+1,j) - solve(i+1,j-1);
    if (s[i] == s[j]) res += 1 * (i == j - 1 || pa[i+1][j-1]);
    return f[i][j] = res;
}

bool check (int i, int j)
{
    if (f[i][j] != -1) return f[i][j];
    if(i > j) return true;
    if (s[i] != s[j]) return false;
    return f[i][j] = check(i + 1, j - 1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen (file".inp","r",stdin);
//    freopen (file".out","w",stdout);
    cin >> s >> q;
    s = "." + s;
    memset(f,-1,sizeof f);
    memset(pa,false,sizeof pa);
    for (int i=1;i<sz(s);++i) f[i][i] = 1, pa[i][i] = true;
    for (int i=1;i<sz(s);++i)
        for (int j=i+1;j<sz(s);++j)
            pa[i][j] = check(i,j);
    memset(f,-1,sizeof f);
    for (int i=1;i<sz(s);++i) f[i][i] = 1;
    while (q--)
    {
        int i, j;
        cin >> i >> j;
        cout << solve(i,j) << '\n';
    }
    return 0;
}
/*
caaaba
2
1 4
2 3
*/
