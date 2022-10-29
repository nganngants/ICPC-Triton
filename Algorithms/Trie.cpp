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

struct TrieNode {
    TrieNode* child[26];
    int cnt;
    TrieNode() {
        for (int i=0; i<26; ++i)
            child[i]=NULL;
        cnt=0;
    }
};

void TrieInsert(const string &s)
{
    int n=s.length();
    TrieNode* p=root;
    for (int i=0; i<n; ++i) {
        int nxt=s[i]-'a';
        if (p->child[nxt]==NULL)
            p->child[nxt]=new TrieNode();
        p=p->child[nxt];
    }
    ++p->cnt;
}

bool TrieFind(const string &s)
{
    int n=s.length();
    TrieNode* p=root;
    for (int i=0; i<n; ++i) {
        int nxt=s[i]-'a';
        if (p->child[nxt]==NULL)
            return false;
        p=p->child[nxt];
    }
    return p->cnt>0;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    freopen(file".inp","r",stdin);
//    freopen(file".out","w",stdout);

    return 0;
}
