//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "1354A"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int t, a, b, c, d;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> t;

    while(t--)
    {
        cin>> a>> b>> c>> d;

        int e= c- d;
        if(b< a&& e<= 0)
        {
            cout<< -1<< "\n";
            continue;
        }

        if(b>= a){
            cout<< b<< "\n";
            continue;
        }

        int k= (a- b)/ e;
        if((a- b)% e) ++k;

        cout<< b+ k* c<< "\n";
    }


    return 0;
}
