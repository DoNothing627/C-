//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 100000
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "BCAP"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, m, r, c[20], f[mn][10], a[20][20];

void iNit()
{
    cin>> n>> m;
    forr(i, 1, n){
        cin>> c[i];
        r+= c[i];
    }
    ++r;
    forr(i, 1, n)
        forr(j, 1, n)
            cin>> a[i][j];
}

int chek(int x, int v)
{
    forr(i, 0, n- 1)
    {
        if(((x>> i)& 1)== 0&& a[i+ 1][v])
            return 1;
        //if(((x>> i)& 1)== 1&& a[v][i+ 1]) return 2;
    }
    return 0;
}

bool binary(int val)
{
    for(int x= 0; x< (1<< n); ++x)
        forr(j, 1, m)
            f[x][j]= oo;

    forr(i, 0, n- 1)
        f[(1<< i)][1]= c[i+ 1];

    for(int x= 0; x< (1<< n); ++x)
        forr(i, 0, n- 1)
            if(((x>> i)& 1)== 0&& chek(x, i+ 1)){
                forr(j, 1, m){
                    if(f[x][j]== oo) continue;
                    if(f[x][j]+ c[i+ 1]<= val)
                        f[x+ (1<< i)][j]= min(f[x+ (1<< i)][j], f[x][j]+ c[i+ 1]);
                    else if(c[i+ 1]<= val)
                        f[x+ (1<< i)][j+ 1]= min(f[x+ (1<< i)][j+ 1], c[i+ 1]);
                }
            }

    forr(i, 1, m)
        if(f[(1<< n)- 1][i]!= oo)
             return 1;
    return 0;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    iNit();

    int l= 0;
    while(r- l> 1){
         int mid= (l+ r)/ 2;
         if(binary(mid)) r= mid;
         else l= mid;
    }

    binary(10);

    cout<< r;

    return 0;
}
