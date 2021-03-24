//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "1224C"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int p, n, w, d, x, y, z;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> p>> w>> d;

    if(w== d){
        if(p% w|| p/ w> n) cout<< -1<< "\n";
        else
            cout<< 1<< " "<< p/ w- 1<< " "<< n- p/ w<< "\n";
        return 0;
    }
    if(w> d){
        int lx= -1, rx= p/ w+ 1;
        while(rx- lx> 1){
            int mx= (lx+ rx)/ 2;
            x= mx, y= (p- x* w)/ d;
            if(x+ y< n) rx= mx;
            else lx= mx;
        }
        x= lx, y= (p- x* w)/ d;
        if(x* w+ y* d== p&& x+ y<= n&& x>= 0&& y>= 0){
             cout<< x<< " "<< y<< " "<< n- x- y<< "\n";
             return 0;
        }
        x= rx, y= (p- x* w)/ d;
        if(x* w+ y* d== p&& x+ y<= n&& x>= 0&& y>= 0){
             cout<< x<< " "<< y<< " "<< n- x- y<< "\n";
             return 0;
        }
        cout<< -1<< "\n";
        return 0;
    }

    else{
        int lx= -1, rx= p/ w+ 1;
        while(rx- lx> 1){
            int mx= (lx+ rx)/ 2;
            x= mx, y= (p- x* w)/ d;
            if(x+ y< n) lx= mx;
            else rx= mx;
        }
        x= rx, y= (p- x* w)/ d;
        if(x* w+ y* d== p&& x+ y<= n&& x>= 0&& y>= 0){
            cout<< x<< " "<< y<< " "<< n- x- y<< "\n";
            return 0;
        }
        x= lx, y= (p- x* w)/ d;
        if(x* w+ y* d== p&& x+ y<= n&& x>= 0&& y>= 0){
            cout<< x<< " "<< y<< " "<< n- x- y<< "\n";
            return 0;
        }
        cout<< -1<< "\n";
        return 0;
    }

    cout<< -1;


    return 0;
}
