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
const int N = 200003;
const ll mod = 1e9 + 7;
typedef pair<int,int> ii;

int n;
int par[N], pre[N];

int getpar (int x)
{
    if (par[x] == x) return x;
    return par[x] = getpar(par[x]);
}

int main()
{
//    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen (file".inp","r",stdin);
//    freopen (file".out","w",stdout);
    int test;
    scanf("%d%d",&n,&test);
    for (int i=1;i<=n;++i) par[i] = i, pre[i] = i - 1;
    while (test--)
    {
        int type, x, y;
        scanf("%d%d%d",&type,&x,&y);
        if (type == 1) par[getpar(x)] = getpar(y);
        else if (type == 2)
        {
            int i = y, j = 0;
            while (pre[i] >= x && i >= x)
            {
                j = pre[i];
                par[getpar(j)] = getpar(i);
                pre[i] = pre[j];
                i = j;
            }
        }
        else if (getpar(x) == getpar(y)) puts("YES");
        else puts("NO");

    }
    return 0;
}
