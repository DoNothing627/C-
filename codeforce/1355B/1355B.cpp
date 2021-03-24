//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 300005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1355B"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int t, res, n, a[mn];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    //freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> t;
    while(t--){
        cin>> n;
        forr(i, 1, n) cin>> a[i];
        sort(a+ 1, a+ n+ 1);

        res= 0;
        while(n> 0){
            ++res;
            n-= a[n];
        }

        cout<< res<< "\n";

    }

    return 0;
}
