//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 105
#define pb push_back
#define oo 100000000000000007
#define int long long
#define DoNothing "BARIC"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n, e, a[mn], f[mn][mn], d[mn][mn], c;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> e;
    forr(i, 1, n) cin>> a[i];

    //forr(i, 0, n+ 1) f[0][i]= f[i][n+ 1]= oo;
    forr(i, 1, n- 1)
        forr(j, i+ 1, n)
        {
            forr(k, i+ 1, j- 1)
            {
                c= abs(2* a[k]- a[i]- a[j]);
                f[i][j]+= c;
                if(f[i][j]> e){
                    f[i][j]= oo;
                    goto over;
                }

            }
            over:;
        }


    forr(i, 1, n)
    {
        forr(j, 1, i- 1)
        {
            c= 2* abs(a[j]- a[i]);
            f[0][i]+= c;
            if(f[0][i]> e){
                f[0][i]= oo;
                goto _over;
            }

        }
        _over:;
    }

    forr(i, 1, n)
    {
        forr(j, i+ 1, n)
        {
            c= 2* abs(a[j]- a[i]);
            f[i][n+ 1]+= c;
            if(f[i][n+ 1]> e){
                f[i][n+ 1]= oo;
                goto __over;
            }
        }
        __over:;
    }

    forr(i, 0, n+ 1)
        forr(j, 0, n+ 1)
            d[i][j]= oo;

    d[0][0]= 0, f[0][n+ 1]= oo;

    forr(k, 1, n)
        forr(i, 1, n+ 1)
            forr(j, 0, i- 1)
                d[i][k]= min(d[i][k], d[j][k- 1]+ f[j][i]);

    forr(i, 1, n)
        if(d[n+ 1][i]<= e)
        {
            cout<< i- 1<< " "<< d[n+ 1][i]<< "\n";
            break;
        }


    return 0;
}
