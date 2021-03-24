//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 1000005
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "SEAKAM"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int t, n, m, g[mn], C[8][mn], num[mn], res= 0, cnt;
bool av[mn], ok;
vector< int> a[mn], d;
ii p[7];

int mod(int x)
{
    x%= oo;
    while(x< 0) x+= oo;
    return x;
}

void dfs(int u, int o)
{
    ++cnt, av[u]= 1;
    for(auto v: a[u])
    {
        if(av[v]&& v!= o){
            ok= 1;
            return;
        }
        if(v== o) continue;
        ++num[u], ++num[v];
        dfs(v, u);
    }
}

void xuly(int type)
{
    int c= 0;
    cnt= 0, ok= 0;
    for(auto u: d)
    {
        if(!av[u]&& a[u].size()){
            dfs(u, 0);
            ++c;
        }
    }
    for(auto u: d)
        if(num[u]> 2) return;

    if(ok) return;

    int ans= 0;
    forr(i, 1, c)
    ans= mod(ans+ mod(mod((1<< c)* mod(g[c]* C[i- 1][c- 1]* C[i][n- cnt+ 1]))* g[n- cnt]));
    if(!type) type= -1;
    res= mod(res+ type* ans);
}

void RESET()
{
    res= 0;
    d.clear();
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);


    g[0]= 1;
    forr(i, 1, 1e6)
        g[i]= (g[i- 1]* i)% oo;

    forr(i, 0, 1e6) C[0][i]= 1;

    forr(i, 1, 7)
        forr(j, 1, 1e6)
            C[i][j]= (C[i- 1][j- 1]+ C[i][j- 1])% oo;

    cin>> t;

    while(t--){
        RESET();
        cin>> n>> m;
        forr(i, 1, m)
        {
            int u, v;
            cin>> u>> v;
            if(u> v) swap(u, v);
            p[i- 1]= ii(u, v);
            d.pb(u), d.pb(v);
        }
        forr(z, 1, (1<< m)- 1)
        {
            int c= 0;
            forr(i, 0, m- 1)
            {
                if((z>> i)& 1)
                {
                    a[p[i].x].pb(p[i].y);
                    a[p[i].y].pb(p[i].x);
                    ++c;
                }
            }
            xuly(c% 2);
            for(auto u: d){
                a[u].clear();
                av[u]= 0;
                num[u]= 0;
            }
        }
        cout<< mod(g[n]- res)<< "\n";
    }

    return 0;
}
