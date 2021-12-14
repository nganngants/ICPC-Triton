//FAST MAXIMUM MATCHING
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>

using namespace std;

struct Matching
{
    int x,y,res;
    vector <int> mx,my;
    vector <vector<int> > a;
    vector <int> dist;

    Matching (int x, int y): x(x), y(y), mx(x+1,0), my(y+1,0),
        a(x+1), dist(x+1), res(0) {}

    void add (int u, int v)
    {
        a[u].push_back(v);
    }

    bool bfs ()
    {
        queue <int> q;
        bool found = false;
        for (int i=1;i<=x;++i)
            if (!mx[i])
        {
            dist[i] = 0;
            q.push(i);
        }
            else dist[i] = -1;

        while (q.size())
        {
            int u = q.front();
            q.pop();
            for (auto v : a[u])
                if (!my[v]) found = true;
                else if (dist[my[v]] < 0)
                {
                    dist[my[v]] = dist[u] + 1;
                    q.push(my[v]);
                }
        }
        return found;
    }

    bool dfs (int u)
    {
        for (auto v : a[u])
            if (!my[v] || (dist[my[v]] == dist[u] + 1 && dfs(my[v])))
        {
            my[v] = u;
            mx[u] = v;
            return true;
        }
        return false;
    }

    void match ()
    {
        while (bfs())
        {
            for (int i=1;i<=x;++i)
                if (!mx[i] && dfs(i)) res++;
        }
    }
};
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int x,y,k;
    cin >> x >> y >> k;
    Matching new_Matching (x,y);
    while (k--)
    {
        int u,v;
        cin >> u >> v;
        new_Matching.add(u,v);
    }
    new_Matching.match();
    cout << new_Matching.res;
    return 0;
}
