//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 1005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing ""
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)
using namespace std;

int n, m, q, res= 0, lit[mn], match[mn], ans= 0, NO[mn];
bool av[mn], found, ok= true;
vector< int> a[mn];

void dfs(int u)
{
    for(auto v: a[u])
    {
        //int v= a[u][i];
        if(av[v]|| NO[v]) continue;
        av[v]= 1;
        if(!match[v]) found= 1;
        else dfs(match[v]);
        if(found== 1){
            match[v]= u;
            return;
        }
    }
}

void RESET()
{
    res= 0;
    memset(match, 0);
    ok= 1;
}

void COW()
{
    //RESET();
    long nlist= n;
    forr(i, 1, n) lit[i]= i;
    while(ok){
        ok= false;
        memset(av, 0);
        forr(i, 1, nlist)
        {
            found= 0;
            dfs(lit[i]);
            if(found== 1){
                lit[i]= lit[nlist];
                nlist--;
                ok= true;
            }
        }
    }
    forr(i, 1, n+ 1) if(match[i]) ++res;
    //cout<< res;
    if(res== n) ++ans;

    RESET();

}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("VOROOM.inp", "r", stdin);
    //freopen("nkbm.out", "w", stdout);
    cin>> n;
    forr(i, 1, n)
    {
        int u, v;
        cin>> u>> v;
        a[i].pb(u), a[i].pb(v);
    }
    //++n;

    forr(i, 1, n+ 1)
    {
        NO[i]= 1;
        COW();
        NO[i]= 0;
    }

    cout<< ans* n- ans* (ans- 1)/ 2;

}
