//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "FCCUP18"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int a[2], b[2];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    //freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> a[0]>> b[0]>> b[1]>> a[1];

    if(a[0]+ a[1]> b[1]+ b[0]) cout<< "A wins";
    else{
        if(a[0]+ a[1]< b[1]+ b[0]) cout<< "B wins";
        else{
              if(a[1]> b[0]) cout<< "A wins";
              else{
                  if(a[1]< b[0]) cout<< "B wins";
                  else cout<< "Extra time";
              }
        }
    }

    return 0;
}
