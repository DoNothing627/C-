//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 10005
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "PALIN"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, m, a[25], l[mn], r[mn], g[mn], res= oo, F[mn][9000];
bool o[mn][15];
string s;

int calc(int x)
{
    x%= oo;
    while(x< 0) x+= oo;
    return x;
}

bool chek(int u, int v)
{
    int t= v- u+ 1;
    int A= calc(l[v]- l[u- 1]* g[t]), B= calc(r[u]- r[v+ 1]* g[t]);
    return (A== B);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> s;
    m= s.size();
    s= " "+ s;
    cin>> n;
    forr(i, 1, n)
    cin>> a[i];

    g[0]= 1;
    forr(i, 1, m)
    g[i]= (g[i- 1]* 131)% oo;

    forr(i, 1, m)
    l[i]= (l[i- 1]* 131+ s[i])% oo;

    for(int i= m; i> 0; i--)
    r[i]= (r[i+ 1]* 131+ s[i])% oo;

    forr(i, 1, m)
    {
        forr(j, 1, n)
        if(i+ a[j]- 1<= m&& chek(i, i+ a[j]- 1))
        {
            o[i+ a[j]- 1][j]= 1;
            F[i+ a[j]- 1][1<< (j- 1)]= i;
        }
    }

    //memset(F, -1);
    //F[0][0]= 0;

    forr(i, 1, m)
    {
        forr(x, 0, (1<< n)- 1)
            F[i][x]= max(F[i][x], F[i- 1][x]);
        forr(j, 1, n)
        {
            if(i+ a[j]- 1<= m&& o[i+ a[j]- 1][j])
            {
                forr(x, 0, (1<< n)- 1)
                {
                    if((x>> (j- 1))& 1) continue;
                    F[i+ a[j]- 1][x+ (1<< (j- 1))]= max(F[i+ a[j]- 1][x+ (1<< (j- 1))], F[i- 1][x]);
                }
            }
        }
    }

    forr(i, 1, m)
    if(F[i][(1<< n)- 1])
        res= min(res, i- F[i][(1<< n)- 1]+ 1);

    if(res== oo) cout<< -1;
    else cout<< res;

    return 0;
}
