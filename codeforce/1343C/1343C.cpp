//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 200005
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "1343C"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int t, n, a[mn], f[2], c[2];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> t;

    while(t--){
        cin>> n;
        f[0]= f[1]= 0;
        c[0]= c[1]= 0;
        forr(i, 1, n){
            cin>> a[i];
            if(a[i]> 0){
                if(f[0]== f[1]+ 1)
                    c[0]= max(c[0], c[1]+ a[i]);
                if(f[0]< f[1]+ 1){
                    f[0]= f[1]+ 1;
                    c[0]= c[1]+ a[i];
                }
            }

            else{
                if(f[1]== f[0]+ 1)
                    c[1]= max(c[1], c[0]+ a[i]);
                if(f[1]< f[0]+ 1){
                    f[1]= f[0]+ 1;
                    c[1]= c[0]+ a[i];
                }
            }
        }
        //cout<< c[0]? c[1]: f[0]> f[1]<< "\n";
        if(f[0]== f[1]){
            cout<< max(c[0], c[1])<< "\n";
            continue;
        }
        if(f[0]> f[1]) cout<< c[0]<< "\n";
        else cout<< c[1]<< "\n";
    }

    return 0;
}
