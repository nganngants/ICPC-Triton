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
int k;

ll tonum (string x)
{
    ll ret = 0;
    for (int i=0;i<sz(x);++i)
        ret = ret * 10 + (x[i] - '0');
    return ret;
}

string toString (ll x)
{
    string ret = "";
    while (x)
    {
        ret = char(x%10 + '0') + ret;
        x /= 10;
    }
    return ret;
}

int d[10], cnt;

string proc (string t)
{
    cnt = 0;
    memset(d,0,sizeof d);
    string temp = "";
    int pos = -1;
    for (int i=0;i<sz(t);++i)
    {
        d[t[i] - '0']++;
        if (d[t[i] - '0'] == 1) cnt++;
        if (cnt <= k) temp += t[i];
        cout << temp << '\n';
    }
    if(temp == t) return t;
    int remain = sz(t) - sz(temp);
    temp = toString(tonum(temp) + 1);
    for (int i=1;i<=remain;++i) temp += '0';
    return temp;
}

void solve()
{
    string t = s;
    while (1)
    {
        string temp = proc(t);
        cout << t << " " << temp << '\n';
        if (temp == t)
        {
            cout << temp << '\n';
            return;
        }
        t = temp;
    }
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
        cin >> s >> k;
        solve();
    }
    return 0;
}
