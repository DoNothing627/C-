//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 105
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "APPLE"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, q, f[mn][105], d[mn];
vector< ii> a[mn];

void dfs(int u, int o)
{
    for(int i= 0; i< a[u].size(); i++)
    {
        int v= a[u][i].x, w= a[u][i].y;
        if(v== o) continue;
        dfs(v, u);
        d[u]+= d[v];
        int val= d[v]- 1;
        for(int j= d[u]- 1; j> 0; j--)
            for(int k= 0; k<= min(j- 1, val); k++)
                if(j- k- 1>= 0) f[u][j]= max(f[u][j], f[u][j- k- 1]+ f[v][k]+ w);
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    cin>> n>> q;
    forr(i, 1, n- 1)
    {
        int u, v, w;
        cin>> u>> v>> w;
        a[u].pb(ii(v, w));
        a[v].pb(ii(u, w));
    }
    forr(i, 1, n) d[i]= 1;

    dfs(1, 0);

    cout<< f[1][q];

    return 0;
}
