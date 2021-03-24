//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1301D"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;
int n, m, k, res= 0;

void rcs(int a, int b)
{
    if(a<= 0|| b<= 0) return;


}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);


    cin>> n>> m>> k;

    if(k> 1000000){
        cout<< "NO";
        return 0;
    }

    rcs(n, m);

    return 0;
}
