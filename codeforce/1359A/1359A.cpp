//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "1359A"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int t, n, m, k, c, d, e;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> t;
    while(t--){
        cin>> n>> m>> k;
        c= n/ k;
        if(c>= m){
            cout<< m<< "\n";
            continue;
        }
        else{
            d= m- c;
            if(d% (k- 1)) e= d/ (k- 1)+ 1;
            else e= d/ (k- 1);
            cout<< c- e<< "\n";
        }
    }

    return 0;
}
