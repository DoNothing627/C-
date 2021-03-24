//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "1271A"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int a, b, c, d, e, f;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> a>> b>> c>> d>> e>> f;

    int g= min(a, d), h= min(b, min(c, d));

    if(e> f){
        cout<< g* e+ min(d- g, h)* f;
    }

    else{
        cout<< h* f+ min(d- h, g)* e;
    }

    return 0;
}
