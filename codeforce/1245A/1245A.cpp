//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 10005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1245A"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int t, a, b, c[mn], d[mn];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    //freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> t;
    while(t--){

        cin>> a>> b;

        if(a== 1|| b== 1){
            cout<< "Finite\n";
            continue;
        }

        if(a% b== 1|| b% a== 1){
            cout<< "Finite\n";
            continue;
        }

        cout<< "Infinite\n";

    }

    return 0;
}
