//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 1000005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "WATERMOV"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

double res= 0, n, a[mn], ans= 0;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    cin>> n;
    forr(i, 1, n)
    {
        cin>> a[i];
        if(a[i]> a[i- 1]) ans= 1;
        else{
            res+= (ans+ 1)* ans* (a[i- 1]- (ans* a[i- 1]+ a[i])/ (ans+ 1))/ 2;
            a[i]= (ans* a[i- 1]+ a[i])/ (ans+ 1);
            ++ans;
        }
    }

    cout<< fixed<< setprecision(1)<< res;

    return 0;
}
