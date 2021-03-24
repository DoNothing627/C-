//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1343B"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int t, a, c, n;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> t;


    while(t--){
        cin>> n;
        c= n/ 2, a= 0;
        if(c% 2){
            cout<< "NO\n";
            continue;
        }
        cout<< "YES\n";
        forr(i, 1, c){
            cout<< 2* i<< " ";
            a+= 2* i;
        }
        forr(i, 1, c- 1){
            cout<< 2* i- 1<< " ";
            a-= (2* i- 1);
        }
        cout<< a<< "\n";
    }

    return 0;
}
