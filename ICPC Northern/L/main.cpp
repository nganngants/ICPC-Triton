#include <bits/stdc++.h>

#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define mid ((l+r)>>1)
#define sz(a) (int)a.size()
#define file "test"

using namespace std;

const ll oo = 2e18;
const int N = 100003;
const int64_t mod = 998244353;
typedef pair<int,int> ii;

int n, k;
int a[N];
int64_t P[N];
//vector <int> b(100000);

int64_t Pow (int a, int p)
{
    if (p == 0) return 1;
    if (p == 1) return a;
    int64_t ans = Pow(a,p / 2) % mod;
    if (p % 2) return (ans * ans % mod * a) % mod;
    return (ans * ans) % mod;
}
int main()
{
//    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen (file".inp","r",stdin);
//    freopen (file".out","w",stdout);
    P[0] = 1;
    P[1] = 2;
    for (int i=2;i<N;++i) P[i] = (P[i - 1] * (int64_t)2) % mod, P[i] %= mod;
    while (1)
    {
        scanf("%d",&n);
        if (n == 0) return 0;
        k = 0;
        for (int i=1;i<=n;++i)
        {
            scanf("%d",&a[i]);
//            cout << n << " " << a[i] << '\n';
            if (a[i] != i && a[i] > 0) k++;
        }
        if (k == 0)
        {
            printf("0\n");
        }
        else
        {
            int64_t res = P[n];
            int64_t temp = P[n - k];
            int64_t t = res - temp - 1;
            t += mod * mod;
            t %= mod;
            printf("%" PRId64 "\n",t);
        }
    }
//    vector <int> b(100000);
//    for (int i=0;i<10000;++i) b[i] = i + 1;
//    for (int i=1;i<=10;++i)
//    {
//        cout << 100000 << '\n';
//        random_shuffle(b.begin(),b.end());
//        for (int j=0;j<100000;++j) cout << b[j] << " ";
//        cout << '\n';
//    }
//    cout << "0";
//    cout << Pow(2,100000);
    return 0;
}
