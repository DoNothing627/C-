//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1081A"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int t, n, x, d, y, c, z, ans;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> t;
    while(t--){
        cin>> n>> x>> y>> d;
        ans= abs(y- x);
        if(ans% d== 0) cout<< ans/ d<< "\n";
        else{
            ans= oo;
            c= (x- 1)/ d+ (y- 1)/ d+ 1;
            //if((x- 1)% d) ++c;
            //if((y- 1)% d) ++c;
            z= (n- x)/ d+ (n- y)/ d+ 1;
            //if((n- x)% d) ++z;
            //if((n- y)% d) ++z;
            if((y- 1)% d== 0) ans= min(ans, c);
            if((n- y)% d== 0) ans= min(ans, z);
            if(ans== oo) cout<< -1<< "\n";
            else cout<< ans<< "\n";
        }
    }


    return 0;
}
