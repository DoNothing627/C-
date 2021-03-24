//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "c11nhl"
#define PI 3.1415926535897
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n, m, k, t[2005][2005], lazy[2005][2005], ans;
double a[505][505];
vector< ii> res;
typedef pair< double, ii> iii;

vector< iii> pq;


bool cmp(iii A, iii B)
{
    //return A.x== B.x? A.y.x< B.y.x: A.x> B.x;
    if(A.x== B.x)
    {
        if(A.y.x== B.y.x) return A.y.y< B.y.y;
        return A.y.x< B.y.x;
    }
    return A.x> B.x;
}

double calc(int u, int v, int _u, int _v)
{
    return a[_u][_v]- a[u- 1][_v]- a[_u][v- 1]+ a[u- 1][v- 1];
}

void up(int kx, int lx, int rx, int ky, int ly, int ry, int u, int v, int x, int y, int val)
{
    if(lx> x|| rx< u|| ly> y|| ry< v) return;
    //t[kx][ky]= max(t[kx][ky], val);
    if(u<=lx&&rx<=x&&v<=ly&&ry<=y){
        t[kx][ky]= max(t[kx][ky], val);
        lazy[kx][ky]= max(lazy[kx][ky], val);
        return;
    }
    int mx= (lx+ rx)/ 2, my= (ly+ ry)/ 2;
    if(lazy[kx][ky])
    {
        up(2* kx, lx, mx, 2* ky, ly, my, lx, ly, rx, ry, lazy[kx][ky]);
        up(2* kx, lx, mx, 2* ky+ 1, my+ 1, ry, lx, ly, rx, ry, lazy[kx][ky]);
        up(2* kx+ 1, mx+ 1, rx, 2* ky, ly, my, lx, ly, rx, ry, lazy[kx][ky]);
        up(2* kx+ 1, mx+ 1, rx, 2* ky+ 1, my+ 1, ry, lx, ly, rx, ry, lazy[kx][ky]);
        lazy[kx][ky]= 0;
    }
    up(2* kx, lx, mx, 2* ky, ly, my, u, v, x, y, val);
    up(2* kx, lx, mx, 2* ky+ 1, my+ 1, ry, u, v, x, y, val);
    up(2* kx+ 1, mx+ 1, rx, 2* ky, ly, my, u, v, x, y, val);
    up(2* kx+ 1, mx+ 1, rx, 2* ky+ 1, my+ 1, ry, u, v, x, y, val);
    t[kx][ky]= max(t[2* kx][2* ky], max(t[2* kx][2* ky+ 1], max(t[2* kx+ 1][2* ky], t[2* kx+ 1][2* ky+ 1])));
}

void get(int kx, int lx, int rx, int ky, int ly, int ry, int u, int v, int x, int y)
{
    if(lx> x|| rx< u|| ly> y|| ry< v) return;
    //if(lx<= u&& rx>= x&& ly<= v&& ry>= y){
    if(u<=lx&&rx<=x&&v<=ly&&ry<=y){
        ans= max(ans, t[kx][ky]);
        return;
    }
    int mx= (lx+ rx)/ 2, my= (ly+ ry)/ 2;
    if(lazy[kx][ky])
    {
        up(2* kx, lx, mx, 2* ky, ly, my, lx, ly, rx, ry, lazy[kx][ky]);
        up(2* kx, lx, mx, 2* ky+ 1, my+ 1, ry, lx, ly, rx, ry, lazy[kx][ky]);
        up(2* kx+ 1, mx+ 1, rx, 2* ky, ly, my, lx, ly, rx, ry, lazy[kx][ky]);
        up(2* kx+ 1, mx+ 1, rx, 2* ky+ 1, my+ 1, ry, lx, ly, rx, ry, lazy[kx][ky]);
        lazy[kx][ky]= 0;
    }
    get(2* kx, lx, mx, 2* ky, ly, my, u, v, x, y);
    get(2* kx, lx, mx, 2* ky+ 1, my+ 1, ry, u, v, x, y);
    get(2* kx+ 1, mx+ 1, rx, 2* ky, ly, my, u, v, x, y);
    get(2* kx+ 1, mx+ 1, rx, 2* ky+ 1, my+ 1, ry, u, v, x, y);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> m>> n>> k;

    forr(i, 1, m)
    {
        double x;
        forr(j, 1, n)
        {
            cin>> x;
            a[i][j]= a[i- 1][j]+ a[i][j- 1]- a[i- 1][j- 1]+ log(x);
            //cout<< a[i][j]<< " ";
        }
        //cout<< "\n";
    }

    forr(i, 1, m)
    {
        forr(j, 1, n)
        {
            if(i+ k- 1> m|| j+ k- 1> n) continue;

            double c= calc(i, j, i+ k- 1, j+ k- 1);
            //cout<< c<< " "<< i<< " "<< j<< " ";
            pq.pb(iii(c, ii(i, j)));

        }
        //cout<< "\n";
    }

    sort(pq.begin(), pq.end(), cmp);

    memset(t, 0);
    memset(lazy, 0);

    for(auto z: pq)
    {
        int u= z.y.x, v= z.y.y, _u= u+ k- 1, _v= v+ k- 1;
        ans= 0;
        get(1, 1, m, 1, 1, n, u, v, _u, _v);
        if(ans) continue;
        res.pb(ii(u, v));
        up(1, 1, m, 1, 1, n, u, v, _u, _v, 1);
    }


    cout<< res.size()<< "\n";
    for(auto z: res)
        cout<< z.x<< " "<< z.y<< "\n";

	return 0;
}
