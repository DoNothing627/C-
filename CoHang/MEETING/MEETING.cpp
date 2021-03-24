//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 1005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "MEETING"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)
using namespace std;

int n, d[mn], z[mn], f[3], F[mn][mn], save;
vector< int> a[mn], X[2];
ii p[mn];

void dfs(int u)
{
    ++f[d[u]];
    for(auto v: a[u])
    {
        if(d[v]) continue;
        d[v]= 3- d[u];
        dfs(v);
    }
}

void visit(int u)
{
    X[d[u]].pb(u);
    for(auto v: a[u])
    {
        if(d[v]) continue;
        d[v]= 3- d[u];
        visit(v);
    }
}

void trace(int sum, int id)
{
    if(!id) return;
    if(sum- p[id].x>= 0&& F[id- 1][sum- p[id].x]){
        z[id]= 1;
        trace(sum- p[id].x, id- 1);
        return;
    }
    z[id]= 2;
    trace(sum- p[id].y, id- 1);
}


main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    cin>> n;

    int u, v;
    while(cin>> u>> v)
    {
        a[u].pb(v);
        a[v].pb(u);
    }

    int m= 0;
    forr(i, 1, n)
        if(!d[i]){
            d[i]= 1, f[1]= f[2]= 0;
            dfs(i);
            p[++m]= ii(f[1], f[2]);
        }

    F[0][0]= 1;
    forr(i, 1, m)
    {
        forr(j, 0, n/ 2)
            if(F[i- 1][j]){
                F[i][j+ p[i].x]= 1;
                F[i][j+ p[i].y]= 1;
            }
    }

    for(int i= n/ 2; i> 0; i--)
    if(F[m][i]){
        save= i;
        break;
    }

    trace(save, m);

    memset(d, 0);
    m= 0;

    forr(i, 1, n)
    if(!d[i]){
        ++m;
        d[i]= z[m];
        visit(i);
    }

    cout<< X[1].size()<< " "<< X[2].size()<< "\n";
    for(auto e: X[1]) cout<< e<< " ";
    cout<< "\n";
    for(auto e: X[2]) cout<< e<< " ";

    return 0;
}
