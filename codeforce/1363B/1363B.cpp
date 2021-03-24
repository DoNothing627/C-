//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1363B"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int t, n, res, f[1005], x, y;
string s;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> t;
    while(t--){
        cin>> s;
        n= s.length();
        if(n< 3){
            cout<< 0<< "\n";
            continue;
        }
        res= oo;
        forr(i, 0, n- 1){
            f[i+ 1]= f[i];
            if(s[i]== '0') ++f[i+ 1];
        }
        forr(i, 1, n)
            res= min(res, min(f[i]+ n- i- f[n]+ f[i], i- f[i]+ f[n]- f[i]));
        res= min(res, min(f[n], n- f[n]));
        cout<< res<< "\n";
    }

    return 0;
}
