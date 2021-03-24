//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 1005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "NKFLOW"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, m, s, t, res= 0, trace[mn];
vector< int> a[mn];

struct data
{
    int u, v, c, f;
    data(){}
    data(int _u, int _v, int _c)
    {
        u= _u, v= _v, c= _c, f= 0;
    }
};

vector< data> e;

bool bfs()
{
    memset(trace, -1);
    queue< int> q;
    q.push(s);
    while(q.size())
    {
        int u= q.front();
        q.pop();
        for(auto id: a[u])
        {
            int v= e[id].v;
            if(trace[v]< 0&& e[id].c> e[id].f){
                trace[v]= id;
                q.push(v);
                if(v== t) return 1;
            }
        }
    }
    return 0;
}

void up()
{
    int v= t, del= 1e18;
    while(v!= s)
    {
        int id= trace[v];
        del= min(del, e[id].c- e[id].f);
        v= e[id].u;
    }
    v= t;
    while(v!= s)
    {
        int id= trace[v];
        e[id].f+= del;
        e[id^ 1].f-= del;
        v= e[id].u;
    }
    res+= del;
}

void cow()
{
    while(bfs())
        up();
    cout<< res;
}

void read()
{
    cin>> n>> m>> s>> t;
    forr(i, 1, m)
    {
        int u, v, w;
        cin>> u>> v>> w;
        a[u].pb(e.size());
        e.pb(data(u, v, w));
        a[v].pb(e.size());
        e.pb(data(v, u, 0));
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    read();
    cow();

    return 0;
}
