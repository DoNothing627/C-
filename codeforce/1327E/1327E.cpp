//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 200005
#define pb push_back
#define oo 998244353
#define int long long
#define DoNothing "1327E"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, f[mn], g[mn];

void init()
{
    f[0]= 1;
    forr(i, 1, n)
    f[i]= (f[i- 1]* 10)% oo;
}

int calc(int x)
{
    return x% oo;
}

int doIt(int x)
{
    int res= 0;
    if(x== n) return 10;
    if(x== n- 1) return 180;

    res= calc(f[n- x- 1]* 180);
    res= calc(res+ calc(f[n- x- 2]* 810* (n- x- 1)));

    return res;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n;

    init();

    forr(i, 1, n)
        cout<< doIt(i)<< "\n";

    return 0;
}
