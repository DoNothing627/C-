//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "1087B"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, k, a, c, res= 100000000000000;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> k;

    if(!n){
        cout<< 0;
        return 0;
    }

    forr(i, 1, k- 1)
    {
        if(n< i) break;
        if(n% i) continue;
        a= n/ i;
        c= a* k+ i;
        res= min(res, c);
    }

    cout<< res;

    return 0;
}
