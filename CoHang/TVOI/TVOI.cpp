//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "TVOI"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int k, n;
double c[2505], s[2505], v[2505], d[2505][2505];
vector< int> a[2505];

void dfs(int u)
{
    d[u][0]= 0, d[u][1]= c[u];
    for(auto v: a[u])
    {
        dfs(v);
        for(int i= k+ 1; i> 0; i--)
            forr(j, 1, i- 1)
            {
                if(d[v][j]== -oo) break;
                d[u][i]= max(d[u][i], d[v][j]+ d[u][i- j]);
            }
    }
}

bool chek(double m)
{
    memset(d, -40);
    forr(i, 1, n)
    {
        double cl= v[i], gt= m* s[i];
        c[i]= cl- gt;
    }
    dfs(0);
    if(d[0][k+ 1]>= 0) return 1;
    return 0;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> k>> n;

    forr(i, 1, n)
    {
        int p;
        cin>> s[i]>> v[i]>> p;
        a[p].pb(i);
    }

    double l= 0, r= 25000000;
    int t= 60;

    while(t--){
        double mid= (l+ r)/ 2;
        if(chek(mid)) l= mid;
        else r= mid;
    }

    cout<< fixed<< setprecision(3)<< l;

    return 0;
}
