//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 4000005
#define pb push_back
#define oo 100000000007
//#define int long long
#define DoNothing "PBCPOINT"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n, MAXX[2005], MINX[2005], MAXY[2005], MINY[2005], a[2005][2005], res= 0;
ii p[mn];
queue< ii> q;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n;

    memset(MAXX, 0);
    memset(MAXY, 0);
    memset(MINY, 40);
    memset(MINX, 40);

    forr(i, 1, n){
        cin>> p[i].x>> p[i].y;
        p[i].x+= 1001, p[i].y+= 1001;
        q.push(ii(p[i].x, p[i].y));
        MAXX[p[i].y]= max(MAXX[p[i].y], p[i].x);
        MINX[p[i].y]= min(MINX[p[i].y], p[i].x);
        MAXY[p[i].x]= max(MAXY[p[i].x], p[i].y);
        MINY[p[i].x]= min(MINY[p[i].x], p[i].y);
    }

    while(q.size())
    {
        int u= q.front().x, v= q.front().y;
        q.pop();
        if(u== MINX[v]|| u== MAXX[v]){
            forr(i, MINX[v], MAXX[v])
                if(!a[i][v]){
                    q.push(ii(i, v));
                    a[i][v]= 1;
                    MAXY[i]= max(MAXY[i], v);
                    MINY[i]= min(MINY[i], v);
                }
        }
        if(v== MINY[u]|| v== MAXY[v]){
            forr(i, MINY[u], MAXY[u])
                if(!a[u][i]){
                    q.push(ii(u, i));
                    a[u][i]= 1;
                    MAXX[i]= max(MAXX[i], u);
                    MINX[i]= min(MINX[i], u);
                }
        }
    }

    forr(i, 1, 2001)
    forr(j, 1, 2001)
    if(a[i][j]) ++res;

    cout<< res;

    return 0;
}
