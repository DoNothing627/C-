//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 1000005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1095E"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, f[mn], c[mn], d[mn], res= 0;
string s;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> s;
    s= " "+ s;
    forr(i, 1, n)
    {
        f[i]= f[i- 1];
        if(s[i]== '(') ++f[i];
        else --f[i];
    }

    c[n+ 1]= 1;
    for(int i= n; i> 0; i--)
    {
        if(!c[i+ 1]){
            c[i]= 0;
            continue;
        }
        if(f[i]< -2) c[i]= 0;
        else c[i]= 1;
    }

    d[n+ 1]= 1;
    for(int i= n; i> 0; i--)
    {
        if(!d[i+ 1]){
            d[i]= 0;
            continue;
        }
        if(f[i]< 2) d[i]= 0;
        else d[i]= 1;
    }

    forr(i, 1, n)
    {
        if(s[i]== '('){
           if(d[i]&& f[n]== 2) ++res;
        }
        else
           if(c[i]&& f[n]== -2) ++res;
        if(f[i]< 0) break;
    }

    cout<< res;

    return 0;
}
