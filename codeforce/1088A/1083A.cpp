//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1083A"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int x;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> x;

    forr(a, 1, x)
        forr(b, 1, x)
        {
            if(a% b== 0){
                if(a* b> x&& a/ b< x){
                    cout<< a<< " "<< b;
                    return 0;
                }
            }
        }

    cout<< -1;
    return 0;
}
