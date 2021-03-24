//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "1294A"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int t, a, b, c, n;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> t;
    while(t--){
        cin>> a>> b>> c>> n;
        int d= a+ b+ c+ n, f= max(a, max(b, c));
        if(d% 3){
            cout<< "NO\n";
            continue;
        }
        d/= 3;
        if(d>= f) cout<< "YES\n";
        else cout<< "NO\n";
    }

    return 0;
}
