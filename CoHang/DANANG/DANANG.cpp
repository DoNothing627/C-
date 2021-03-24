//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 200005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "DANANG"
#define PI 3.1415926535897
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

typedef pair< int, ii> iii;
int n, m, d;
long long f[mn][2], res= 1e15;
vector< int> a[mn];
vector< iii> s;

void COW()
{
    forr(i, 0, m)
        f[i][0]= f[i][1]= 1e15;

    priority_queue< iii> q;

    q.push(iii(0, ii(1, -1)));
    while(q.size())
    {
        int trace= q.top().y.y, u= q.top().y.x, val= -q.top().x, type;
        q.pop();
        if(trace== -1){
            for(int j= 0; j< a[u].size(); j++)
            {
                int i= a[u][j];
                int _u= s[i].y.x, _v= s[i].y.y, w= s[i].x;
                if(u== _u){
                    type= 1;
                    swap(_u, _v);
                }
                else type= 0;
                if(f[i][type]> val+ w){
                    f[i][type]= val+ w;
                    q.push(iii(-f[i][type], ii(_u, i)));
                }
            }
        }
        else{
            int vex= s[trace].y.x;
            if(vex== u) type= 1;
            else type= 0;
            if(val!= f[trace][1- type]) continue;
            for(int j= 0; j< a[u].size(); j++)
            {
                int i= a[u][j];
                int _u= s[i].y.x, _v= s[i].y.y, w= s[i].x;
                if(w- s[trace].x< d) continue;
                if(u== _u){
                    type= 1;
                    swap(_u, _v);
                }
                else type= 0;
                if(f[i][type]> val+ w){
                    f[i][type]= val+ w;
                    q.push(iii(-f[i][type], ii(_u, i)));
                }
            }
        }
    }

    for(int j= 0; j< a[n].size(); j++)
    {
        int i= a[n][j];
        int type;
        int u= s[i].y.x, v= s[i].y.y;
        if(u== n) type= 0;
        else type= 1;
        res= min(res, f[i][type]);
    }

    if(res== 1e15) cout<< -1;
    else cout<< res;

}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> m>> d;

    forr(i, 1, m)
    {
        int u, v, w;
        cin>> u>> v>> w;
        a[u].pb(s.size());
        a[v].pb(s.size());
        s.pb(iii(w, ii(u, v)));
    }

    COW();

    return 0;
}
