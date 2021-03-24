//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 205
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "WAVE"
#define ii pair< double, double>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n;
ii p[mn];


double dist(double a, double b, int i)
{
    return sqrt((a- p[i].x)* (a- p[i].x)+ (b- p[i].y)* (b- p[i].y));
}

double calc(double a, double b)
{
    double ans= 0;
    forr(i, 1, n)
    ans= max(ans, dist(a, b, i));
    return ans;
}

double chek(double m)
{
    double l= 0, r= 1e5;
    int c= 100;
    while(c--)
    {
        double m1= l+ (r- l)/ 3, m2= r- (r- l)/ 3;
        if(calc(m, m1)< calc(m, m2)) r= m2;
        else l= m1;
    }
    return calc(m, l);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n;
    forr(i, 1, n)
    cin>> p[i].x>> p[i].y;

    double l= 0, r= 1e5;
    int c= 100;

    while(c--){
        double m1= l+ (r- l)/ 3, m2= r- (r- l)/ 3;
        if(chek(m1)< chek(m2)) r= m2;
        else l= m1;
    }

    double res= chek(l);

    cout<< fixed<< setprecision(6)<< res;
    return 0;
}
