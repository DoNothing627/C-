//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 200005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1354B"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int t, f[5][mn];
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
        int n= s.length();
        int res= oo;
        f[1][0]= f[2][0]= f[3][0]= -oo;
        for(int i= 1; i<= n; i++){
            if(s[i- 1]== '1'){
                f[1][i]= i;
                f[2][i]= f[2][i- 1];
                f[3][i]= f[3][i- 1];
                res= min(res, i- min(f[2][i], f[3][i])+ 1);
            }
            if(s[i- 1]== '2'){
                f[2][i]= i;
                f[1][i]= f[1][i- 1];
                f[3][i]= f[3][i- 1];
                res= min(res, i- min(f[1][i], f[3][i])+ 1);
            }
            if(s[i- 1]== '3'){
                f[3][i]= i;
                f[2][i]= f[2][i- 1];
                f[1][i]= f[1][i- 1];
                res= min(res, i- min(f[2][i], f[1][i])+ 1);
            }
        }
        if(f[1][n]== -oo|| f[2][n]== -oo|| f[3][n]== -oo) res= 0;
        cout<< res<< "\n";
    }

    return 0;
}
