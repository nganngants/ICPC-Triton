#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include <vector>
#include <algorithm>

#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define mid ((l+r)>>1)
#define file "MILITARY"

using namespace std;

const ll oo = 2e18;
const int N = 100003;
typedef pair<int,int> ii;

struct point
{
    int x,y;
    bool operator < (point temp)
    {
        return (x != temp.x ? x < temp.x : y < temp.y);
    }
    bool operator == (point temp)
    {
        return x == temp.x && y == temp.y;
    }
};
int n,cnt=0;
vector <point> a,res;

void enter()
{
    cin >> n;
    a.resize(n);
    for (auto &it : a) cin >> it.x >> it.y;
}

int ori (point p1, point p2, point p3)
{
    ll x = (p3.x - p2.x) * (p2.y - p1.y);
    ll y = (p3.y - p2.y) * (p2.x - p1.x);
    if (x == y) return 0; //thang
    if (x > y) return 1; //phai
    return -1;//trai
}

vector <point> take (point p1, point p2, int o)
{
    vector <point> ans;
    ans.pb(p1);
    for (int i=1;i<(int)a.size();++i)
        if (i == a.size() - 1 || ori(p1,a[i],p2) == o)
    {
        while (ans.size() >= 2 && ori(ans[ans.size()-2],ans.back(),a[i]) != o)
            ans.pop_back();
        ans.pb(a[i]);
    }
    return ans;
}

void get_res (vector <point> up, vector <point> down)
{
    res.clear();
    for (auto i : up) res.pb(i);
    for (int i=down.size()-2;i>=0;--i) res.pb(down[i]);
}

void convexhull()
{
    sort(a.begin(),a.end());
    point p1 = a[0], p2 = a.back();
    vector <point> up = take(p1,p2,1), down = take(p1,p2,-1);
    get_res(up,down);
    up.clear(); down.clear();
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    freopen(file".inp","r",stdin);
//    freopen(file".out","w",stdout);
    enter();
    convexhull();
    res.pop_back();
    for (auto it : res) cout << it.x << " " << it.y << '\n';
    return 0;
}
