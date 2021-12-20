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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen (file".inp","r",stdin);
//    freopen (file".out","w",stdout);
    string s;
    getline(cin,s);
    int n = sz(s) - 1;
    if (s[n] == 'y' || s[n] == 'Y')
        if (s[n - 1] == 'p' || s[n - 1] == 'P')
        if (s[n - 2] == '.')
    {
        cout << "yes";
        return 0;
    }
    cout << "no";
    return 0;
}
