//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 100005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "BICYCLE"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, c= 200;
double eps= 1e-9;
ii a[mn];

double calc(double e)
{
    double MAX= -1e18, MIN= 1e18;
    forr(i, 1, n)
    {
        MIN= min(MIN, (double) a[i].x+ (double) e* a[i].y);
        MAX= max(MAX, (double) a[i].x+ (double) e* a[i].y);
    }
    return MAX- MIN;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);
    //freopen(DoNothing".inp", "w", stdout);

    cin>> n;
    forr(i, 1, n)
        cin>> a[i].x>> a[i].y;

    double l= 0, r= 1e9;

    while(c--)
    {
        double m1= l+ (r- l)/ 3, m2= r- (r- l)/ 3;
        if(calc(m1)<= calc(m2)+ eps) r= m2;
        else l= m1;
    }

    double ans= calc(l);
    cout<< fixed<< setprecision(6)<< l<< " "<< ans;

//    n= 100000;
//    cout<< n<< "\n";
//    forr(i, 1, n)
//    cout<< i/ 2<< " "<< n- i+ 1<< "\n";

    return 0;
}
