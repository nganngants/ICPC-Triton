#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define fi first
#define se second
#define pb push_back
#define mid ((l+r)>>1)
#define sz(a) (int)a.size()
#define fu(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define bit(x,i) (int)((x>>i)&1)
#define file ""

using namespace std;
using namespace __gnu_pbds;
typedef tree<
int,
null_type,
///less -> set, less_equal -> multiset
less_equal<int>,
rb_tree_tag,
tree_order_statistics_node_update> ordered_set;

const ll oo = 2e18;
const int N = 300003;
const int M = 1000003;
const ll mod = 1e9 + 7;
typedef pair<ll, ll> ii;

bool isPrime[M+1];
void sieve(int M)
{
    for(int i = 0; i <= M; ++i)
    {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i * i <= M; ++i)
    {
        if(isPrime[i] == true)
        {
            // Mark all the multiples of i as composite numbers
            for(int j = i * i; j <= M; j += i)
                isPrime[j] = false;
        }
    }
}
int minPrime[M + 1];

void sieveForFact(int M)
{
    for (int i = 2; i * i <= M; ++i)
        if (minPrime[i] == 0)   //if i is prime
            for (int j = i * i; j <= M; j += i)
                if (minPrime[j] == 0) minPrime[j] = i;
    for (int i = 2; i <= M; ++i)
        if (minPrime[i] == 0) minPrime[i] = i;
}

vector<int> factorize(int n)
{
    vector<int> res;
    while (n != 1)
    {
        res.push_back(minPrime[n]);
        n /= minPrime[n];
    }
    return res;
}

int L, R;
vector<bool> isPrime(R - L + 1, true);  // x là số nguyên tố khi và chỉ khi isPrime[x - l] == true

void segmentSieve()
{

    for (long long i = 2; i * i <= R; ++i) {
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
        {
            isPrime[j - L] = false;
        }
    }

    if (1 >= L) {  // Xét riêng trường hợp số 1
        isPrime[1 - L] = false;
    }

    for (long long x = L; x <= R; ++x) {
        if (isPrime[x - L]) {
            // i là số nguyên tố
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen(file".inp","r",stdin);
//    freopen(file".out","w",stdout);

    return 0;
}
