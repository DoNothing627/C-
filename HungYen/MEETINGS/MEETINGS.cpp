//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 10000000000000007
//#define int long long
#define DoNothing "MEETINGS"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

long long n, p, v, res;

long long calc(int a, int u, int b, int v)
{
    long long ans= 1;
    forr(i, 1, u) ans= 1ll* ans* a;
    forr(i, 1, v) ans= 1ll* ans* b;
    return ans;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    cin>> n>> p>> v;

    int k= log2(n);

    res= n* p+ v;

    forr(i, 2, k)
    {
        int a= pow(n, 1.0/ i);
        int b= a+ 1;
        forr(j, 0, i)
            if(calc(a, j, b, i- j)>= n) res= min(res, (a* j+ b* (i- j))* p+ i* v);
    }

    cout<< res;

    //cout<< f[n];

    return 0;
}
