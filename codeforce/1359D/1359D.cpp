//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 100005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1359D"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, a[mn], I[2][4* mn], L[mn], R[mn], f[mn], g[mn], c[2], ans, res= -oo;

void init(int k, int l, int r)
{
    if(l== r){
        I[0][k]= f[l];
        I[1][k]= g[l];
        return;
    }
    int m= (l+ r)/ 2;
    init(2* k, l, m);
    init(2* k+ 1, m+ 1, r);
    I[0][k]= min(I[0][2* k], I[0][2* k+ 1]);
    I[1][k]= min(I[1][2* k], I[1][2* k+ 1]);
}

void get(int k, int l, int r, int u, int v)
{
    if(l> v|| r< u) return;
    if(u<= l&& r<= v){
        c[0]= min(c[0], I[0][k]);
        c[1]= min(c[1], I[1][k]);
        return;
    }
    int m= (l+ r)/ 2;
    get(2* k, l, m, u, v);
    get(2* k+ 1, m+ 1, r, u, v);
}

void creat()
{
    a[0]= oo, a[n+ 1]= oo;
    forr(i, 1, n)
    {
        if(a[i]< a[i- 1]) L[i]= i- 1;
        else{
            int j= L[i- 1];
            while(a[i]>= a[j]) j= L[j];
            L[i]= j;
        }
    }

    R[n+ 1]= n+ 1;
    for(int i= n; i> 0; i--)
    {
        if(a[i]< a[i+ 1]) R[i]= i+ 1;
        else{
            int j= R[i+ 1];
            while(a[i]>= a[j]) j= R[j];
            R[i]= j;
        }
    }

}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n;
    f[0]= g[n+ 1]= 0;
    forr(i, 1, n){
        cin>> a[i];
        f[i]= f[i- 1]+ a[i];
    }
    for(int i= n; i> 0; i--)
        g[i]= g[i+ 1]+ a[i];

    init(1, 1, n);

    creat();
    forr(i, 1, n){
        int trai= L[i]+ 1, phai= R[i]- 1;
        ans= f[phai]- f[trai- 1];
        c[0]= oo, c[1]= oo;
        get(1, 1, n, trai, i- 1);
        if(c[0]!= oo&& c[0]< f[L[i]]) ans-= (c[0]- f[L[i]]);
        c[0]= oo, c[1]= oo;
        get(1, 1, n, i+ 1, phai);
        if(c[1]!= oo&& c[1]< g[R[i]]) ans-= (c[1]- g[R[i]]);
        ans-= a[i];
        res= max(res, ans);
    }

    cout<< res;

    return 0;
}
