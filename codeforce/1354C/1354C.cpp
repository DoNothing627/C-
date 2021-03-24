//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1354C"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)
#define PI 3.14159265

using namespace std;

int t, n;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> t;
    while(t--){
        cin>> n;
        double p= PI/ 2/ n;
        double r= 0.5/ sin(p);
        double h= sqrt(r* r- 0.5* 0.5);
        h*= 2, r*= 2;
        cout<< setprecision(9)<< fixed<< r<< "\n";
    }

    return 0;
}
