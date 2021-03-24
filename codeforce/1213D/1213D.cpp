//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 200005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1213D"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, k, d, dem= 0, lev[mn], c[mn], in[mn], out[mn], C= oo, f[20][mn];
vector< int> a[mn];
vector< ii> V[mn];

void dfs(int u)
{
    in[u]= ++ dem;
    V[lev[u]].pb(ii(in[u], u));
    for(auto v: a[u])
    {
        lev[v]= lev[u]+ 1;
        dfs(v);
    }
    out[u]= dem;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> k;

    forr(i, 1, n)
    {
        int x;
        cin>> x;
        ++c[x], d= max(d, x);
    }

    for(int i= 1; 2* i<= d; ++i)
        a[i].pb(2* i), a[i].pb(2* i+ 1);

    dfs(1);

    forr(i, 0, lev[d])
        for(int j= 0; j< V[i].size(); ++j)
            f[i][j+ 1]= f[i][j]+ c[V[i][j].y];

    forr(i, 0, d) V[i].pb(ii(mn, 0));

    forr(i, 1, d)
    {
        //for(auto v: V[i]) cout<< v.x<< " ";
        //cout<< "\n";
        int ans= 0, res= 0;
        forr(j, lev[i], lev[d])
        {
             int l= lower_bound(V[j].begin(), V[j].end(), ii(in[i], 0))- V[j].begin();
             int r= lower_bound(V[j].begin(), V[j].end(), ii(out[i]+ 1, 0))- V[j].begin();
             ans+= f[j][r]- f[j][l];
             res+= (j- lev[i])* (f[j][r]- f[j][l]);
             if(ans>= k){
                ans-= k;
                res-= ans* (j- lev[i]);
                C= min(C, res);
                break;
             }
        }
    }

    cout<< C;

    return 0;
}
