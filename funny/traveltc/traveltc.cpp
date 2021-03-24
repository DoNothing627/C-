//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 1005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "traveltc"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, m, k, f[mn][mn], r[mn* mn], d= 0;
ii a[mn];
char c[mn];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    cin>> n>> m>> k;

    forr(i, 1, n)
    cin>> a[i].x>> a[i].y;

    forr(i, 1, m) cin>> c[i];

    int u= 1, v= 1;

    while(!f[u][v]){
        f[u][v]= ++d;
        if(c[v]== 'L') u= a[u].x;
        else u= a[u].y;
        v= (v+ 1)% m;
        if(!v) v= m;
        r[d]= u;
    }

    ++d;
    if(k* m< f[u][v]) cout<< r[k* m];

    else cout<< r[f[u][v]+ (1ll* k* m- f[u][v])% (d- f[u][v])] /* f[u][v]+ (k* m- f[u][v])% (d- f[u][v])*/;

    return 0;
}
