//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 500005
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "DRVTRUCK"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, k, p[mn], ROOT, ans, F[mn], f[mn], g[mn], r[mn];
vector< ii> a[mn];
vector< int> save[mn], V;
bool chek[mn];

void dfs(int u)
{
    for(int i= 0; i< a[u].size(); i++)
    {
        int v= a[u][i].x;
        if(v== p[u]) continue;
        p[v]= u;
        dfs(v);
    }
}

void DFS(int u)
{
    for(int i= 0; i< a[u].size(); i++)
    {
        int v= a[u][i].x, w= a[u][i].y;
        if(v== p[u]|| !chek[v]) continue;
        ans+= w;
        DFS(v);
        save[u].pb(f[v]+ w);
    }
    sort(save[u].begin(), save[u].end());
    reverse(save[u].begin(), save[u].end());
    if(save[u].size()) f[u]= save[u][0];
}

void _DFS(int u)
{
    for(int i= 0; i< a[u].size(); i++)
    {
        int v= a[u][i].x, w= a[u][i].y;
        if(v== p[u]|| !chek[v]) continue;
        g[v]= g[u]+ w;
        if(f[v]!= f[u]- w) g[v]= max(g[v], f[u]+ w);
        else if(f[v]== f[u]- w&& save[u].size()> 1)
            g[v]= max(g[v], save[u][1]+ w);
        _DFS(v);
        //save[u].pb(f[v]+ w);
    }
}

void C(int u)
{
    for(int i= 0; i< a[u].size(); i++)
    {
        int v= a[u][i].x, w= a[u][i].y;
        if(v== p[u]) continue;
        if(chek[v])
            r[v]= v;
        else{
            F[v]= F[u]+ w;
            r[v]= r[u];
        }
        C(v);
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> k;
    forr(i, 1, n- 1)
    {
        int u, v, w;
        cin>> u>> v>> w;
        a[u].pb(ii(v, w));
        a[v].pb(ii(u, w));
    }

    forr(i, 1, k)
    {
        int u;
        cin>> u;
        V.pb(u);
        ROOT= u;
    }

    dfs(ROOT);

    for(int i= 0; i< V.size(); i++)
    {
        int u= V[i];
        while(!chek[u]){
            chek[u]= 1;
            u= p[u];
        }
    }

    DFS(ROOT);
    _DFS(ROOT);
    r[ROOT]= ROOT;
    C(ROOT);

    forr(i, 1, n)
    cout<< F[i]+ 2* ans- max(f[r[i]], g[r[i]])<< "\n";

    return 0;
}
