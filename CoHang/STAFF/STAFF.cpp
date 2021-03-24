//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 100005
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "STAFF"
#define PI 3.1415926535897
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, m, t, k, c[mn], f[mn];
vector< ii> a[mn];
priority_queue< ii> q;
bool chek[mn];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> m>> t;
    forr(i, 1, n)
    cin>> c[i];

    forr(i, 1, m)
    {
        int u, v, w;
        cin>> u>> v>> w;
        a[u].pb(ii(v, w));
        a[v].pb(ii(u, w));
        c[u]+= w, c[v]+= w;
    }

    forr(i, 1, n) f[i]= c[i];

    while(t--){
        cin>> k;
        while(q.size()) q.pop();
        forr(i, 1, n)
        {
            q.push(ii(- c[i], i));
            chek[i]= 1;
            f[i]= c[i];
        }
        int u= q.top().y, COUNT= 0;
        while(f[u]<= k&& q.size()){
            q.pop();
            if(!chek[u]) goto over;
            chek[u]= 0;
            ++COUNT;
            for(int i= 0; i< a[u].size(); i++)
            {
                int v= a[u][i].x, w= a[u][i].y;
                if(chek[v]){
                    f[v]-= w;
                    q.push(ii(- f[v], v));
                }
            }
            over:;
            if(q.size()) u= q.top().y;
            //else break;
        }
        cout<< n- COUNT<< " ";
    }


    return 0;
}
