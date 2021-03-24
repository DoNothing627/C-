//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 10000000000000007
#define int long long
#define DoNothing "NKBUILD"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n, m, k, c[10], a[105][105], f[130][105], res= oo;


main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> m>> k;

    forr(i, 1, k) cin>> c[i];

    memset(a, 60);
    forr(i, 1, m)
    {
         int u, v, w;
         cin>> u>> v>> w;
         a[u][v]= min(a[u][v], w);
         a[v][u]= a[u][v];
    }

    forr(i, 1, n) a[i][i]= 0;

    forr(i, 1, n)
        forr(u, 1, n)
            forr(v, 1, n)
                a[u][v]= min(a[u][v], a[u][i]+ a[i][v]);

    memset(f, 60);
    forr(i, 1, k)
        forr(j, 1, n)
            f[1<< (i- 1)][j]= a[c[i]][j];

    forr(i, 1, n) f[0][i]= 0;
    for(int c = 1; c < (1 << k); ++c) {
		for(int a = 0; a < c; ++a) {
			if((a | c) != c) continue;
			int b = c ^ a;
			if(b > a) continue;
			for(int v = 1; v <= n; ++v) {
				f[c][v] = min(f[c][v], f[a][v] + f[b][v]);
			}
		}
    }
    forr(i, 1, n)
        res= min(res, f[(1<< k)- 1][i]);

    cout<< res;

    return 0;
}
