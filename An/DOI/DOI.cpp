//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 1000005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "DOI"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, a[mn], l[mn][2], r[mn][2], c[2];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n;
    forr(i, 1, n)
       cin>> a[i];
    a[0]= a[1], a[n+ 1]= a[n];

    forr(i, 1, n){
        l[i][0]= i, l[i][1]= i;
        if(a[i]> a[i- 1])
            l[i][1]= l[i- 1][1];
        if(a[i]< a[i- 1])
            l[i][0]= l[i- 1][0];
    }

    for(int i= n; i> 0; i--){
        r[i][0]= i, r[i][1]= i;
        if(a[i]> a[i+ 1])
            r[i][1]= r[i+ 1][1];
        if(a[i]< a[i+ 1])
            r[i][0]= r[i+ 1][0];
    }

    forr(i, 1, n)
    {
        c[0]= max(c[0], min(i- l[i][0], r[i][0]- i));
        c[1]= max(c[1], min(i- l[i][1], r[i][1]- i));
    }

    cout<< c[1]<< " "<< c[0];

    return 0;
}
