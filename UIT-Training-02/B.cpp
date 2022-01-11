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
int n,resM = 0, resL = 0;
vector <int> memo;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen (file".inp","r",stdin);
//    freopen (file".out","w",stdout);
    cin >> s >> n;
    memo.pb(s[0] - '0');
    resL = s[0] - '0';
    for (int i=2;i<sz(s);i+=2)
    {
        if (s[i - 1] == '*')
        {
            int pre = memo.back();
            memo.pop_back();
            memo.pb(pre * (s[i] - '0'));
            resL *= (s[i] - '0');
        }
        else
        {
            memo.pb(s[i] - '0');
            resL += (s[i] - '0');
        }
    }
    for (auto it : memo) resM += it;
    if (resL == resM && resM == n) cout << "U";
    else if (resL == n) cout << "L";
    else if (resM == n) cout << "M";
    else cout << "I";
    return 0;
}
