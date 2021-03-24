//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 100005
#define pb push_back
#define oo 10000000000007
#define int long long
#define DoNothing "675E"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, a[mn], f[mn];
long long I[4* mn], c[mn], res= 0;

void up(int k, int l, int r, int u)
{
    if(l> u|| r< u) return;
    if(l== r){
        I[k]= c[u]+ u;
        return;
    }
    int m= (l+ r)/ 2;
    up(2* k, l, m, u);
    up(2* k+ 1, m+ 1, r, u);
    I[k]= min(I[2* k], I[2* k+ 1]);
}

int get(int k, int l, int r, int u, int v)
{
    if(l> v|| r< u) return oo;
    if(l>= u&& r<= v) return I[k];
    int m= (l+ r)/ 2;
    return min(get(2* k, l, m, u, v), get(2* k+ 1, m+ 1, r, u, v));
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    //freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    /*cin>> n;
    forr(i, 1, n- 1)
        cin>> a[i];

    forr(i, 1, 4* n)
        I[i]= oo;

    up(1, 1, n, n);
    for(int i= n- 1; i> 0; i--)
    {
        c[i]= get(1, 1, n, i+ 1, a[i])+ n- i- a[i];
        res+= c[i];
        up(1, 1, n, i);
    }

    cout<< res;*/

    while(! (1&& 0)) cout<< 1;

    return 0;
}
