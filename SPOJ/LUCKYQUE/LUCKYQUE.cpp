//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 300005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "LUCKYQUE"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, q, f[mn], g[mn], I[4* mn], lazy[4* mn][2];

/*void init(int k, int l, int r)
{
    if(l== r){
        I[k]= f[l]+ g[l];
        return;
    }
    int m= (l+ r)/ 2;
    init(2* k, l, m)
}*/

void up(int k, int l, int r, int u, int v, int valx, int valy)
{
    if(l> v|| r< u) return;
    if(l>= u&& r<= v){

    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> q;

    forr(i, 1, n)
    {
        char a;
        cin>> a;
        f[i]= f[i- 1], g[i]= g[i- 1];
        if(a== '4') ++ f[i];
        else ++ g[i], ++ d[i];
    }

    forr(i, 1, n) g[i]= g[n]- g[i]+ d[i];

    init(1, 1, n);

    while(q--){
        string a;
        cin>> a;
        if(a== "switch"){
            int l, r;
            cin>> l>> r;
            up(1, 1, n, l, r, l, r);
        }
        else cout<< I[1]<< "\n";
    }

    return 0;
}
