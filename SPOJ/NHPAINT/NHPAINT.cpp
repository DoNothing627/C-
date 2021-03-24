//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 10005
#define pb push_back
#define oo 100000000007
//#define int long long
#define DoNothing "NHPAINT"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n, m, a[mn][20], f[20][20], d[20], F[(1<< 16)][20], res= oo, z;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> m>> n;
    forr(i, 1, m)
    forr(j, 1, n)
    {
        char c;
        cin>> c;
        a[i][j]= c- '0';
        if(a[i][j]) ++d[j];
    }

    memset(F, 60);

    forr(i, 0, n- 1) F[(1<< i)][i]= d[i+ 1];
    forr(i, 1, n)
    {
        forr(j, 1, n)
        {
            forr(k, 1, m)
            if(a[k][i]!= a[k][j]) ++f[i][j];
        }
    }

    forr(x, 0, (1<< n)- 1)
    {
        forr(i, 0, n- 1)
        {
            if(!((x>> i)& 1)) continue;
            z= i- 1;
            if(z>= 0&& !((x>> z)& 1)) F[x+ (1<< z)][z]= min(F[x+ (1<< z)][z], F[x][i]+ d[z+ 1]);
            z= i+ 1;
            if(z< n&& !((x>> z)& 1)) F[x+ (1<< z)][z]= min(F[x+ (1<< z)][z], F[x][i]+ d[z+ 1]);
            forr(j, 0, n- 1)
            {
                if((x>> j)& 1) continue;
                F[x+ (1<< j)][j]= min(F[x+ (1<< j)][j], F[x][i]+ f[i+ 1][j+ 1]);
            }
        }
    }

    forr(i, 0, n- 1) res= min(res, F[(1<< n)- 1][i]);
    cout<< res;
    return 0;
}
