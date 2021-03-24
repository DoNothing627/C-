//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 1005
#define pb push_back
#define oo 10000000000000000
#define int long long
#define DoNothing "1293D"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int x[mn], y[mn], ax, bx, ay, bx, X, Y, t, n= 0, res= 0, c, d;

bool chek(int l, int r)
{
    //int ngang= y[r]- y[l], doc= x[r]- x[l], ans= t+ 1;
    if(X< x[l]){
        if(Y< y[l])
            ans= min(ans, x[r]- X+ y[r]- Y);
        if(Y>= y[l]&& Y< y[r])
            ans= min(ans, x[r]- X+ y[r]- y[l]+ 2* (Y- y[l]));
        if(Y>= y[r])
            ans= min(ans, min(x[l]- X+ Y- y[l], x[r]- X+ Y- y[r])+ x[r]- x[l]+ y[r]- y[l]);
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> x[0]>> y[0]>> ax>> bx>> ay>> by>> X>> Y>> t;

    int a= 0, b= 0;
    while(a< 2* oo&& b< 2* oo){
        x[++n]= ax* x[n- 1]+ bx;
        y[n]= ay* y[n- 1]+ by;
        a= x[n], b= y[n];
    }

    /*c= lower_bound(x, x+ n+ 1, X)- x;
    d= lower_bound(y, y+ n+ 1, Y)- y;*/

    forr(i, 0, n)
        forr(j, i, n)
            if(chek(i, j)) res= max(res, j- i+ 1);

    cout<< res;

    return 0;
}
