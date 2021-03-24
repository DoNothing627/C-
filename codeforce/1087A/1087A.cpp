//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1087A"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

string s;
int n, c, d= 0;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> s;
    int n= s.size();
    s= " "+ s;

    c= n/ 2;
    if(n% 2) ++c;

    forr(i, 1, n)
    {
        c+= d;
        cout<< s[c];
        d*= (-1);
        if(i% 2) ++d;
        else --d;
    }

    return 0;
}
