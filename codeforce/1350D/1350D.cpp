//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1350D"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

bool chek()
{
    forr(i, 1, n){
        if(a[i]< k) a[i]= 0;
        if(a[i]== k) a[i]= 1;
        if(a[i]> k) a[i]= 2;
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> t;
    while(t--){
        cin>> n>> k;
        forr(i, 1, n) cin>> a[i];

        cout<< chek()<< "\n";

    }

    return 0;
}
