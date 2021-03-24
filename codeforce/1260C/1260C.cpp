//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1260C"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int t, r, b, k;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> t;
    while(t--){
        int a, b, k;
        cin >> a >> b >> k;
        int c=__gcd(a, b);

        a/= c, b/= c;
        if(a> b) swap (a, b);

        int d= (b+ a- 2)/ a;

        if (d>= k) cout << "REBEL\n";

        else cout << "OBEY\n";

    }

    return 0;
}
