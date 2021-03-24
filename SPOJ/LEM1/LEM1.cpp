//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 10005
#define pb push_back
#define oo 100000000007
//#define int long long
#define DoNothing "LEM1"
#define ii pair< int, int>
#define PI 3.1415926535897
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n, c= 100;
double d[mn];


double calc(double m, double a, double b)
{
    return ((m+ a)* (m+ a)+ (m+ b)* (m+ b)- (a+ b)* (a+ b))/ (m+ a)/ (m+ b)/ 2;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n;
    forr(i, 1, n) cin>> d[i];

    d[0]= d[n];
    double l= 0, r= 1e9;

    while(c--){
        double m= (l+ r)/ 2, ans= 0;
        forr(i, 1, n)
        {
            double a= d[i- 1], b= d[i];
            ans+= acos(calc(m, a, b));
        }
        if(ans< 2* PI) r= m;
        else l= m;
    }

    cout<< fixed<< setprecision(3)<< l;

    return 0;
}









