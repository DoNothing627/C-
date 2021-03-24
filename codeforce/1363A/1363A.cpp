//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1363A"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int t, n, x, c, a, d;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> t;
    while(t--){
        cin>> n>> x;
        c= 0, d= 0;
        forr(i, 1, n){
            cin>> a;
            if(a% 2) ++c;
            else ++d;
        }
        if(c){
            while(c% 2== 0|| c> x) --c;
            if(x- c> d){
                cout<< "No"<< "\n";
                continue;
            }
            cout<< "Yes"<< "\n";
        }
        else cout<< "No"<< "\n";
    }

    return 0;
}
