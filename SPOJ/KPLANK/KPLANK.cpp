//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 1000005
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "KPLANK"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, a[mn], l[mn], r[mn], res= 0;

void doIt()
{
    a[0]= -1, a[n+ 1]= -1;
    forr(i, 1, n)
    {
        if(a[i]> a[i- 1]) l[i]= i- 1;
        else{
            int j= l[i- 1];
            while(a[i]<= a[j]) j= l[j];
            l[i]= j;
        }
    }

    r[n+ 1]= n+ 1;
    for(int i= n; i> 0; i--)
    {
        if(a[i]> a[i+ 1]) r[i]= i+ 1;
        else{
            int j= r[i+ 1];
            while(a[i]<= a[j]) j= r[j];
            r[i]= j;
        }
    }

    res= 0;

    forr(i, 1, n){
        //if(a[i]<= )
        res= max(res, a[i]* (r[i]- l[i]- 1));
    }

    cout<< res<< "\n";

}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    //freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    while(cin>> n){
        if(!n) break;
        forr(i, 1, n) cin>> a[i];
        doIt();
    }

    return 0;
}
