//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 1005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1224B"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int q, n, d[mn][2* mn], res, ans, a[4], trace;
//int a[3]= {-1, 1, -n, n};
int h[2* mn];

void dfs(int u)
{
    //c[u]= 1;
    if(h[u]> res){
        res= h[u];
        trace= u;
    }
    forr(i, 0, 3)
    {
        int v= u+ a[i];
        if(u== n&& v== n+ 1) continue;
        if(u== n+ 1&& v== n) continue;
        if(v<= 0|| v> 2* n) continue;
        if(h[v]) continue;
        if(!d[u][v]) continue;
        h[v]= h[u]+ 1;
        dfs(v);
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> q;
    while(q--){
        cin>> n;
        memset(d, 0);
        res= 0;
        forr(i, 1, n){
            char x;
            cin>> x;
            if(i!= n){
                d[i][i+ 1]= 1;
                d[i+ 1][i]= 1;
                d[i+ n+ 1][i+ n]= 1;
                d[i+ n][i+ n+ 1]= 1;
            }
            if(x== '1'){
                d[i][i+ n]= 1;
                d[i+ n][i]= 1;
            }
        }

        a[0]= 1, a[1]= -1, a[2]= n, a[3]= -n;

        //forr(i, 1, n) dfs(i);
        res= 0;
        h[1]= 1, dfs(1);
        res= 0, memset(h, 0);
        h[trace]= 1, dfs(trace);

        cout<< res<< "\n";
    }

    return 0;
}
