//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1263A"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int t, a[3];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> t;
    while(t--){
        cin>> a[0]>> a[1]>> a[2];
        sort(a, a+ 3);

        if(a[2]>= a[0]+ a[1]){
            cout<< a[0]+ a[1]<< "\n";
        }
        //cout<< min(a[2], a[0]+ a[1])<< "\n";
        else{
            cout<< (a[0]+ a[1]+ a[2])/ 2<< "\n";
        }
    }

    return 0;
}
