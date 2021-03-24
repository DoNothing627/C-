//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "1343A"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int t, n, f[50];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> t;

    f[0]= 1;
    forr(i, 1, 30) f[i]= f[i- 1]* 2;

    while(t--){
        cin>> n;
        forr(i, 2, 30){
            if(n% (f[i]- 1)== 0){
                cout<< n/ (f[i]- 1)<< "\n";
                break;
            }
        }
    }

    return 0;
}
