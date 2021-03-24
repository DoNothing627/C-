#include <bits/stdc++.h>
#define mn 1001
using namespace std;
long n, m, k, a[mn][mn];
long long res, f[mn][mn];

long get(int x, int y, int u, int v)
{
    return f[u][v]- f[x- 1][v]- f[u][y- 1]+ f[x- 1][y- 1];
}

void BUFF()
{
    for(int i= 1; i<= k; i++)
    {
        int x, y, u, v;
        res= 100000000000000;
        cin>> x>> y>> u>> v;
        for(int j= x; j< u; j++)
            res= min(res, abs(get(x, y, j, v)- get(j+ 1, y, u, v)));
        for(int j= y; j< v; j++)
            res= min(res, abs(get(x, y, u, j)- get(x, j+ 1, u, v)));
        cout<< res<< "\n";
    }
}

void FULL()
{
    for(long i= 1; i<= k; i++)
    {
        int x, y, u, v;
        cin>> x>> y>> u>> v;
        long long A= get(x, y, u, v);
        long l= x, r= u;
        while(r- l> 1){
            long mid= (l+ r)/ 2;
            if(get(x, y, mid, v)> A/ 2) r= mid;
            else l= mid;
        }
        res= min(abs(A- 2* get(x, y, r, v)), abs(A- 2* get(x, y, l, v)));
        l= y, r= v;
        while(r- l> 1){
            long mid= (l+ r)/ 2;
            if(get(x, y, u, mid)> A/ 2) r= mid;
            else l= mid;
        }
        res= min(res, min(abs(A- 2* get(x, y, u, r)), abs(A- 2* get(x, y, u, l))));
        cout<< res<< "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("mincut.inp", "r", stdin);
    freopen("mincut.out", "w", stdout);
    cin>> n>> m>> k;
    memset(f, 0, sizeof(0));
    for(long i= 1; i<= n; i++)
        for(long j= 1; j<= m; j++)
        {
            cin>> a[i][j];
            f[i][j]= f[i- 1][j]+ f[i][j- 1]+ a[i][j]- f[i- 1][j- 1];
        }

    BUFF();
    FULL();

    return 0;
}
