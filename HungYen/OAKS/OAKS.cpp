//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 5000005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "OAKS"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, m, N, X[mn], Y[mn];
ii a[mn], u[100005], v[100005];
vector< int> c[2][mn];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    cin>> n;
    //scanf("%d", &n);
    forr(i, 1, n)
    {
        cin>> a[i].x>> a[i].y;
        //scanf("%d%d", & a[i].x, & a[i].y);
        X[i]= a[i].x, Y[i]= a[i].y;
    }

    cin>> m;
    //scanf("%d", &m);
    forr(i, 1, m)
    {
        cin>> u[i].x>> v[i].x>> u[i].y>> v[i].y;
        //scanf("%d%d%d%d", & u[i].x, & v[i].x, & u[i].y, & v[i].y);
        X[n+ i]= u[i].x, Y[n+ i]= v[i].x;
        X[m+ n+ i]= u[i].y, Y[m+ n+ i]= v[i].y;
    }

    int N= n+ 2* m;

    sort(X+ 1, X+ N+ 1);
    sort(Y+ 1, Y+ N+ 1);

    forr(i, 1, m)
    {
        u[i].x= lower_bound(X+ 1, X+ N+ 1, u[i].x)- X;
        u[i].y= lower_bound(X+ 1, X+ N+ 1, u[i].y)- X;
        v[i].x= lower_bound(Y+ 1, Y+ N+ 1, v[i].x)- Y;
        v[i].y= lower_bound(Y+ 1, Y+ N+ 1, v[i].y)- Y;
        //cout<< u[i].x<< " "<< v[i].x<< " "<< u[i].y<< " "<< v[i].y<< "\n";
    }

    forr(i, 1, n)
    {
        a[i].x= lower_bound(X+ 1, X+ N+ 1, a[i].x)- X;
        a[i].y= lower_bound(Y+ 1, Y+ N+ 1, a[i].y)- Y;
        c[0][a[i].x].pb(a[i].y);
        c[1][a[i].y].pb(a[i].x);
    }

    forr(i, 1, N){
        c[0][i].pb(oo), c[1][i].pb(oo);
        sort(c[0][i].begin(), c[0][i].end());
        sort(c[1][i].begin(), c[1][i].end());
    }

//    forr(i, 1, N)
//    {
//        cout<< i<< " ";
//        for(auto z: c[0][i]) cout<< z<< " ";
//        cout<< "\n";
//    }

    forr(i, 1, m)
    {
        int res= 0, l, r;
        if(c[0][u[i].x].size())
        {
            r= upper_bound(c[0][u[i].x].begin(), c[0][u[i].x].end(), v[i].y)- c[0][u[i].x].begin();
            l= lower_bound(c[0][u[i].x].begin(), c[0][u[i].x].end(), v[i].x)- c[0][u[i].x].begin();
            res+= r- l;
        }

        if(c[1][v[i].y].size())
        {
            r= upper_bound(c[1][v[i].y].begin(), c[1][v[i].y].end(), u[i].y- 1)- c[1][v[i].y].begin();
            l= lower_bound(c[1][v[i].y].begin(), c[1][v[i].y].end(), u[i].x+ 1)- c[1][v[i].y].begin();
            res+= r- l;
        }

        if(c[0][u[i].y].size())
        {
            r= upper_bound(c[0][u[i].y].begin(), c[0][u[i].y].end(), v[i].y)- c[0][u[i].y].begin();
            l= lower_bound(c[0][u[i].y].begin(), c[0][u[i].y].end(), v[i].x)- c[0][u[i].y].begin();
            res+= r- l;
        }

        if(c[1][v[i].x].size())
        {
            r= upper_bound(c[1][v[i].x].begin(), c[1][v[i].x].end(), u[i].y- 1)- c[1][v[i].x].begin();
            l= lower_bound(c[1][v[i].x].begin(), c[1][v[i].x].end(), u[i].x+ 1)- c[1][v[i].x].begin();
            res+= r- l;
        }


         cout<< res<< "\n";
         //printf("%d\n", &res);
    }


    return 0;
}
