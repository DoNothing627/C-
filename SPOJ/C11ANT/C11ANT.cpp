//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 100005
#define pb push_back
#define oo 100000000007
//#define int long long
#define DoNothing "C11ANT"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

long long n, a[mn], b[mn], t= 200;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n;

    forr(i, 1, n) cin>> b[i];
    forr(i, 1, n) cin>> a[i];

    double l= 0, r= 1e9;

    while(t--){
        double m= (r- l)/ 3, C= -1e9, D= 1e9;
        forr(i, 1 , n)
        {
            C= max(C, (double) a[i]* (l+ m)+ b[i]);
            D= min(D, (double) a[i]* (l+ m)+ b[i]);
        }
        double ans= C- D;
        C= -1e9, D= 1e9;
        forr(i, 1 , n)
        {
            C= max(C, (double) a[i]* (r- m)+ b[i]);
            D= min(D, (double) a[i]* (r- m)+ b[i]);
        }
        if(ans< C- D) r-= m;
        else l+= m;
    }

    //cout<< l<< " "<< r<< "\n";

    double C= -1e9, D= 1e9, res;
    forr(i, 1, n)
    {
        C= max(C, (double) a[i]* l+ b[i]);
        D= min(D, (double) a[i]* l+ b[i]);
    }

    res= (C- D)/ 2;

    cout<< fixed<< setprecision(3)<< res;

    return 0;
}
