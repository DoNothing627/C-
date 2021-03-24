//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 105
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "STONE"
#define PI 3.1415926535897
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;


int c, m, k, f[mn][32][5], res;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);


    while(cin>> m>> k)
    {
        if(!m) break;

        res= oo;
        memset(f, 40);

        forr(i, 0, k- 1)
        f[0][1<< i][i]= 0;

        forr(i, 1, m)
        {
             cin>> c;
             --c;

             forr(j, 0, k- 1)
             {
                 forr(z, 0, (1<< k)- 1)
                 {
                     if((z>> c)& 1)
                     {
                         if(c== j) f[i][z][c]= min(f[i][z][c], f[i- 1][z][c]);
                     }
                     else
                         //if((z>> j)& 1)
                            f[i][z+ (1<< c)][c]= min(f[i][z+ (1<< c)][c], f[i- 1][z][j]);
                 }
             }

             forr(j, 0, k- 1)
                 forr(z, 0, (1<< k)- 1)
                     //if((z>> j)& 1)
                        f[i][z][j]= min(f[i][z][j], f[i- 1][z][j]+ 1);

        }

        forr(j, 0, k)
            forr(z, 0, (1<< k)- 1)
                res= min(res, f[m][z][j]);

        //cout<< f[6][1][0]<< "\n";

        cout<< res<< "\n";
    }

	return 0;
}
