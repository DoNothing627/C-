//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "1355C"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int a, b, c, d, x, y, z, k, stz, sty, enz, eny, res= 0;

/*void Front(int x)
{
    if(x+ b<= c){

    }
}

void Back(int x)
{
    if(x+ c>= d){
        enz= d;
        eny= c;
    }
    else{
        enz= x+ c;
        eny= c;
    }
    enz= enz- c+ 1;
}*/

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> a>> b>> c>> d;

    forr(x, a, b)
    {
        /*Front(x);
        Back(x);

        res+= (enz- stz+ 1)* (enz+ stz)/ 2+ max(1ll* 0, 1ll* x+ eny- enz- c)* enz;*/

        stz= min(max(x+ b+ 1, c), d);
        enz= min(d, x+ c);

        res+= (enz- stz+ 1)* (enz+ stz)/ 2+ min(x+ c- d, 1ll* 0) * (enz- stz);

    }

    cout<< res;
    return 0;
}
