
#include <bits/stdc++.h>
#define ll long long
#define mid ((l+r)/2)
#define inf (ll)1e17
#define maxn 100001
#define mod (ll)(1e9+7)
#define pi pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define name ""
using namespace std;
ll f[17][4][16*9][16*9];
ll n;
bool prime[maxn];
string s;
void input()
{
     freopen(name".inp","r",stdin);
     freopen(name".out","w",stdout);
}
void Boost()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
ll dp(int idx,int memo, int sum_x, int sum_y,string xx,string yy)
{
    if(idx == s.size())
    {
        if(prime[sum_x]+prime[sum_y]==0 && memo ==0)return 1;
        return 0;
    }
    ll res=0;
    if(f[idx][memo][sum_x][sum_y]!=-1)return f[idx][memo][sum_x][sum_y];
    for(int x=0;x<=9;x++)
        for(int y=0;y<=9;y++)
    {
        if((x+y*2+memo)%10==s[idx]-'0')
            res+=dp(idx+1,(x+y*2+memo)/10,sum_x+x,sum_y+y,xx+char(x+'0'),yy+char(y+'0'));
    }
    return f[idx][memo][sum_x][sum_y]=res;
}
string tostring(ll n)
{
    string s;
    stringstream ss;
    ss<<n;
    ss>>s;
    reverse(s.begin(),s.end());
    return s;
}
void sang()
{
    for(int i=2;i<=9*15;i++)
        if(prime[i]==0)
        for(int j=i*2;j<=9*15;j+=i)
        prime[j]=1;
    prime[0]=prime[1]=1;
}
int main()
{
     cin>>n;
     s=tostring(n);
     memset(f,-1,sizeof(f));
     sang();
     cout<<dp(0,0,0,0,"","");
     return 0;
}
/*
Read the code again
Check the limit
Check IO
*/
