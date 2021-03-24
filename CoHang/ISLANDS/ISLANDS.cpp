//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 1000005
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "ISLANDS"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int m, n, cnt= 0, res= 0, a[1005][1005], d[1005][1005], COUNT= 0, r[mn], C[mn];
int dx[4]= {0, 1, 0, -1};
int dy[4]= {1, 0, -1, 0};
//vector< ii> S[mn];
vector< int> V[mn], c[mn];


int fs(int u)
{
    return !r[u]? u: r[u]= fs(r[u]);
}

void dfs(int u, int v)
{
    d[u][v]= COUNT;
    C[COUNT]= a[u][v];
    forr(i, 0, 3)
    {
        int _u= u+ dx[i], _v= v+ dy[i];
        if(_u< 1|| _u> m|| _v< 1|| _v> n|| a[_u][_v]!= a[u][v]|| d[_u][_v]) continue;
        dfs(_u, _v);
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    cin>> m>> n;
    forr(i, 1, m)
    forr(j, 1, n)
    cin>> a[i][j];

    forr(i, 1, m)
    forr(j, 1, n)
        if(!d[i][j]){
            ++COUNT;
            dfs(i, j);
            V[a[i][j]].pb(COUNT);
        }

    forr(i, 1, m)
    forr(j, 1, n)
    {
        forr(k, 0, 3)
        {
            int _u= i+ dx[k], _v= j+ dy[k];
            if(_u< 1|| _u> m|| _v< 1|| _v> n|| d[_u][_v]== d[i][j]) continue;
            c[d[i][j]].pb(d[_u][_v]);
        }
    }

    for(int i= 9; i> 0; i--)
    {
        for(auto u: V[i])
        {
            ++cnt;
            for(auto v: c[u])
            {
                if(C[v]< C[u]) continue;
                int fu= fs(u), fv= fs(v);
                if(fu!= fv){
                    --cnt;
                    r[fu]= fv;
                }
            }
        }
        res= max(res, cnt);
    }

    cout<< res;
    return 0;
}
