//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 1000005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "D"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, a[mn], b[mn], f[mn], I[mn], res= 0, h[mn];
bool d[mn];

void snt()
{
    d[1]= 1;
    forr(i, 2, 1000000)
    {
        if(!d[i])
            for(long long j= 1ll* i* i; j<= 1000000; j+= i)
                d[j]= 1;
    }
}

/*int power(int a, int b)
{
    int c= 1;
    for(; b> 0; a= (a* a)% oo)
    {
        if(b% 2) c= (c* a)% oo;
        b/= 2;
    }
    return c;
}

void init()
{
    f[0]= 1;
    forr(i, 1, mn)
    f[i]= (f[i- 1]* i)% oo;
    forr(i, 0, mn)
    g[i]= power(f[i], oo- 2);
}

int C(int K, int N)
{
    int ans= (f[N]* g[K])% oo;
    ans= (ans* g[N- K])% oo;
    return ans;
}*/

void up(int x)
{
    while(x< 1000000){
        ++I[x];
        x+= (x& (- x));
    }
}

int get(int x)
{
    int ans= 0;
    while(x> 0){
        ans+= I[x];
        x-= (x& (- x));
    }
    return ans;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    //freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    snt();

//    init();

    cin>> n;
    forr(i, 1, n){
        int x;
        cin>> x;
        a[i]= a[i- 1], b[i]= b[i- 1];
        if(d[x]) ++a[i];
        else ++b[i];
        /*res+= get(a[i]- b[i]);
        up(a[i]+ b[i]);*/
        h[i]= b[i]- a[i];
        f[i]= h[i];
    }
    ++n;
    h[n]= 0;

    sort(h+ 1, h+ n+ 1);

    forr(i, 0, n- 1)
    {
        f[i]= lower_bound(h+ 1, h+ n+ 1, f[i])- h;
        res+= get(f[i]);
        up(f[i]);
    }
    /*forr(i, 1, a)
        D[i]= D[i- 1]+ C(i, a);

    forr(i, 1, b)
        res= mod(res+ mod(C(i, b)* D[i]));*/

    cout<< res;

    return 0;
}
