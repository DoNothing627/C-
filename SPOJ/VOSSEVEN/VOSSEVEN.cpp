//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 1000005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "VOSSEVEN"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int a[mn], n, m= 0;
string s;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> s;
    n= s.size();
    s= " "+ s;

    forr(i, 1, n)
    {
        if(s[i]== '7'){
            ++m;
            ++a[m];
        }
        else m= 0;
    }

    for(int i= n; i> 0; i--)
        a[i]+= a[i+ 1];

    forr(i, 1, n)
    {
        if(!a[i]) break;
        cout<< i<< " "<< a[i]<< "\n";
    }

    return 0;
}
