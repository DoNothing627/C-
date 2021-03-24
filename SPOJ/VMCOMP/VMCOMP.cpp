//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 100005
#define pb push_back
#define oo 100000000007
//#define int long long
#define DoNothing "VMCOMP"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n, m, s, ans, c[mn];
vector< ii> a[mn];
queue< int> q;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> m>> s;

    while(m--)
    {
        int u, v, w;
        cin>> u>> v>> w;
        a[u].pb(ii(v, w));
        a[v].pb(ii(u, w));
        c[u]+= w, c[v]+= w;
    }

    forr(i, 1, n)
    if(c[i]< s) q.push(i);

    int ans= n;
    while(q.size())
    {
        int u= q.front();
        q.pop(), --ans;

        for(auto z: a[u])
        {
            int v= z.x, w= z.y;
            if(c[v]>= s){
                c[v]-= w;
                if(c[v]< s) q.push(v);
            }
        }

    }

    if(!ans) cout<< -1;
    else{
        cout<< ans<< "\n";
        forr(i, 1, n)
        if(c[i]>= s) cout<< i<< " ";
    }

    return 0;
}
