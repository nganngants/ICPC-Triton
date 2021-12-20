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

string s;
int k, n, bonus[303][303], res = 0;
int f[103][103][33]; ///vị trí i, số lần đổi k, kí tự đổi thành c

int num (char x)
{
    return x - 'a';
}

int solve(int id, int remain, int pre)
{
    if (f[id][remain][pre] != -1) return f[id][remain][pre];
    if (id == sz(s)) return 0;
    int res = bonus[pre][num(s[id])] + solve(id + 1,remain,num(s[id]));
    if (remain > 0)
        for (int i=0;i<26;++i)
            if (i != num(s[id]))
            res = max(res,solve(id + 1,remain - 1, i) + bonus[pre][i]);
    return f[id][remain][pre] = res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen (file".inp","r",stdin);
//    freopen (file".out","w",stdout);
    cin >> s >> k >> n;
    for (int i=1;i<=n;++i)
    {
        char x, y;
        int val;
        cin >> x >> y >> val;
        bonus[num(x)][num(y)] = val;
    }
    memset(f,-1,sizeof f);
    cout << solve(0,k,27);
    return 0;
}
