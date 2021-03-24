//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 20005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1083C"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n, a[mn], ans= 0;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n;

    forr(i, 1, n) cin>> a[i];

    cout<< n+ 1<< "\n";

    for(int i= n; i> 0; i--)
    {
        cout<< 1<< " "<< i<< " ";
        int c= (a[i]+ ans)% n;
        cout<< i- 1- c+ n<< "\n";
        ans+= i- 1- c+ n;
    }

    cout<< 2<< " "<< n<< " "<< n;
    return 0;
}
