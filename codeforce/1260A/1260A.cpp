//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1260A"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n;
    forr(i, 1, n)
    {
        int a, b;
        long long ans= 0;
        cin>> a>> b;
        int c= b/ a;
        int d= b- c* a;
        forr(j, 1, d) ans= ans+ 1ll* (c+ 1)* (c+ 1);
        forr(j, d+ 1, a) ans= ans+ 1ll* c* c;
        cout<< ans<< "\n";
    }

    return 0;
}
