//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "FLIPROW"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n, m, d[105], z[2], f[105], res= 0, a[105][105];
vector< int> c[105][2];
bool fail;

void chek(int u, int v)
{
    int o= 0;
    forr(i, 1 ,m)
        if(a[u][i]== a[v][i])
        {
            ++o;
            break;
        }

    if(!o){
        c[u][0].pb(v);
        c[v][0].pb(u);
    }
    int save= o;
    forr(i, 1, m)
        if(a[u][i]== a[v][m- i+ 1])
        {
            ++o;
            break;
        }

    if(o== save){
        c[u][1].pb(v);
        c[v][1].pb(u);
    }

    if(!o){
        c[u][0].pop_back();
        c[v][0].pop_back();
        c[u][1].pop_back();
        c[v][1].pop_back();
    }

    if(o== 2){
        cout<< "NO";
        exit(0);
    }
}


void dfs(int u, int o)
{
    if(d[u]!= -1){
        if(d[u]!= o) fail= 1;
        return;
    }

    d[u]= o;
    ++z[o];

    for(auto v: c[u][0])
        dfs(v, o);

    for(auto v: c[u][1])
        dfs(v, 1- o);

}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    //freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> m;
    forr(i, 1, n)
        forr(j, 1, m)
            cin>> a[i][j];

    forr(i, 1, n- 1)
    {
        forr(j, i+ 1, n)
            chek(i, j);
    }

    fail= 0;

    forr(i, 1, n) d[i]= -1;
    forr(i, 1, n)
    {

        if(d[i]== -1)
        {
            z[0]= z[1]= 0;
            dfs(i, 0);
            if(fail)
            {
                cout<< "NO";
                return 0;
            }

            res+= z[1];
        }

    }

//    forr(i, 1, n) d[i]= -1;
//
//    forr(i, 1, n)
//        if(d[i]== -1)
//            dfs(i, f[i]);

    cout<< "YES\n"<< res<< "\n";

    forr(i, 1 , n)

        if(d[i]) cout<< i<< " ";

    return 0;
}
