//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 505
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "JOBSET"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, m, ans, res= 0, c[mn], cnt, COUNT, cost[mn], dad[mn], num[mn], low[mn], root[mn];
bool d[mn];
vector< ii> V;
vector< int> a[mn];
stack< int> S;

void dfs(int u)
{
    //ans+= c[u], d[u]= 1;
    num[u]= low[u]= ++cnt;
    S.push(u);
    for(auto v: a[u])
    {
        if(num[v])
            low[u]= min(low[u], num[u]);
        else{
            dfs(v);
            low[u]= min(low[u], low[v]);
        }
    }
    if(num[u]== low[u])
    {
        ++COUNT;
        int v;
        while(v!= u)
        {
            v= S.top(), S.pop();
            num[v]= low[v]= oo;
            dad[v]= COUNT;
            cost[COUNT]+= c[v];
        }
    }
}

void DFS(int u)
{
    for(auto v: a[u])
        DFS(v);
    root[cnt]= u;
    --cnt;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n;
    forr(i, 1, n) cin>> c[i];
    cin>> m;
    forr(i, 1, m)
    {
        int u, v;
        cin>> u>> v;
        a[u].pb(v);
        //a[v].pb(u);
        V.pb(ii(u, v));
    }

    forr(i, 1, n)
    {
        if(!num[i]){
            ans= 0;
            dfs(i);
        }
        //if(ans> 0) res+= ans;
    }

    forr(i, 1, n) a[i].clear();
    for(auto z: V)
    {
        int u= dad[z.x], v= dad[z.y];
        if(u!= v)
        a[u].pb(v);
    }

    n= COUNT;
    cnt= n;

    forr(i, 1, n)
        if(!d[i]) DFS(i);

    //DFS()
    forr(i, 1, n)
    {
        int u= root[i];
        for(auto v: a[u])
        {
            cost[v]= max(cost[v], cost[v]+ cost[u]);
        }
    }

    forr(i, 1, n)
    if(a[i].size()== 0)
        res= max(res, res+ cost[i]);

    cout<< res;
    return 0;
}
