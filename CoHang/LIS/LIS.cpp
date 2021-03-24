//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 200005
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "LIS"
#define PI 3.1415926535897
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n, x, I[mn], a[mn], h[mn], f[mn], g[mn], res= 0, c[mn];


void up(int x, int val)
{
    while(x<= 2* n+ 3)
    {
        I[x]= max(I[x], val);
        x+= (x& (- x));
    }
}

int get(int x)
{
    int ans= 0;
    while(x> 0)
    {
        ans= max(ans, I[x]);
        x-= (x& (- x));
    }
    return ans;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    cin>> n>> x;

    forr(i, 1, n)
    {
        cin>> a[i];
        h[i]= a[i];
        h[i+ n]= a[i]- x;
    }

    sort(h+ 1, h+ 2* n+ 1);

    forr(i, 1, n)
    c[i]= lower_bound(h+ 1, h+ 2* n+ 1, a[i]- x)- h+ 1;

    forr(i, 1, n)
    {
        a[i]= lower_bound(h+ 1, h+ 2* n+ 1, a[i])- h+ 1;
        f[i]= get(a[i]- 1)+ 1;
        res= max(res, f[i]);
        up(a[i], f[i]);
    }

    if(!x){
        cout<< res;
        return 0;
    }

    memset(I, 0);

    for(int i= n; i> 0; i--)
    {
        a[i]= 2* n- a[i]+ 2;
        c[i]= 2* n- c[i]+ 2;
        g[i]= get(a[i]- 1)+ 1;
        res= max(res, f[i]+ get(c[i]- 1));
        up(a[i], g[i]);

    }

    cout<< res;


    return 0;
}
