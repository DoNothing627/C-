//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "TALENT"
#define PI 3.1415926535897
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, w, c= 50;
double F[1005][255];

struct data
{
    int x, y;
    double z;
}a[255];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    cin>> n>> w;
    forr(i, 1, n)
        cin>> a[i].x>> a[i].y;

    double l= 0, r= 1e6;
    while(c--){
        double m= (l+ r)/ 2;
        forr(i, 1, n)
        a[i].z= (double)a[i].y- (double) m* a[i].x;
        memset(F, -40);

        F[0][0]= 0;
        int v;
        forr(i, 1, n)
        {
            forr(j, 0, w+ 1) F[j][i]= F[j][i- 1];
            forr(j, 0, w+ 1)
            {
                v= min(w+ 1, j+ a[i].x);
                //if(F[j][i- 1]== F[0][n+ 1]) continue;
                F[v][i]= max(F[v][i], F[j][i- 1]+ a[i].z);
            }
        }
        if(F[w+ 1][n]>= 0) l= m;
        else r= m;
    }

    int res= l* 1000;
    cout<< res;

    return 0;
}
