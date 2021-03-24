//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 1005
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "BRCOUNT"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

string s;
int n, a[mn], f[mn][mn];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> s;
    int n= s.length();

    for(int i= 0; i< n; i++){
        if(s[i]== '(') a[i+ 1]= 0;
        if(s[i]== ')') a[i+ 1]= 1;
        if(s[i]== '?') a[i+ 1]= 2;
    }

    f[0][0]= 1;

    forr(i, 1, n)
    {
        if(a[i]) f[i][0]= f[i- 1][1];
        forr(j, 1, n){
            if(!a[i]) f[i][j]= f[i- 1][j- 1];
            if(a[i]== 1) f[i][j]= f[i- 1][j+ 1];
            if(a[i]== 2) f[i][j]= (f[i- 1][j- 1]+ f[i- 1][j+ 1])% oo;
        }
    }

    cout<< f[n][0];

    return 0;
}
