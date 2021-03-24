//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 1005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "EFILL"
//#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n;
double ans, res, C[4], RES;
struct ii
{
    int x, y, z;
};

ii p[mn], c, d, ROOT, z[10];

long long ccw(ii O, ii A, ii B)
{
    A.x-= O.x, A.y-= O.y;
    B.x-= O.x, B.y-= O.y;
    return 1ll* A.x* B.y- 1ll* A.y* B.x;
}

double dist(ii A, ii B)
{
    return sqrt(1ll* (A.x- B.x)* (A.x- B.x)+ 1ll* (A.y- B.y)* (A.y- B.y));
}

bool sx(ii A, ii B)
{
    if(A.x== B.x)
        return A.y< B.y;
    return A.x< B.x;
}

bool cmp(ii A, ii B)
{
    return ccw(ROOT, A, B)> 0;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n;
    forr(i, 1, n)
    {
        cin>> p[i].x>> p[i].y;
        if(i<= 2) p[i].z= 1;
        else p[i].z= 0;
    }

    cin>> c.x>> c.y>> d.x>> d.y;

    sort(p+ 1, p+ n+ 1, sx);

    ROOT= p[1];

    sort(p+ 2, p+ n+ 1, cmp);

    p[n+ 1]= p[1];

    forr(i, 1, n)
    {
        if(p[i].z== 0|| p[i+ 1].z== 0)
        {
            res+= dist(p[i], p[i+ 1]);
            ans= max(ans, dist(p[i], p[i+ 1]));
        }
    }

    if(ccw(p[1], p[2], c)== 0&& ccw(p[1], p[2], d)== 0)
    {
        z[1]= p[1], z[2]= p[2], z[3]= c, z[4]= d;
        sort(z+ 1, z+ 5, sx);
        RES= res- ans+ dist(z[1], z[4]);
    }

    else{
        C[0]= dist(p[1], c), C[1]= dist(p[1], d), C[2]= dist(p[1], p[2]), C[3]= dist(c, d);
        sort(C, C+ 4);
        RES= res- ans+ C[0]+ C[1]+ C[2];
    }

    cout<< fixed<< setprecision(2)<< RES;

    return 0;
}
