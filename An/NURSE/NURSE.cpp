//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 1005
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "NURSE"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, k[2], f[mn], g[mn];

int calc(int x)
{
    x= x% oo;
    while(x< 0) x+= oo;
    return x;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> k[0]>> k[1];

    //for(int i= n; i> max(0, n- k))
    f[n]= 1;
    for(int i= n- k[0]; i>= n- k[1]; i--)
        //if(k[0]< i) f[i]= 1;
        f[i]= 1;
    for(int i= n; i>= n- k[0]; i--) //g[i]= f[i]+ g[i+ 1];
        g[i]= 1;

    for(int i= n- k[0]; i> 0; i--)
    {
        int l= min(n+ 1, i+ k[0]+ 1), r= min(n+ 1, i+ k[1]+ 2);
        f[i]= calc(f[i]+ g[l]- g[r]);
        g[i]= calc(f[i]+ g[i+ 1]);
    }

    int l= min(n+ 1, k[0]+ 1), r= min(n+ 1, k[1]+ 2);

    cout<< calc(f[1]+ g[l]- g[r]);

    return 0;
}
