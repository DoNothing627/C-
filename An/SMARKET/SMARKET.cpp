//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 100005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "SMARKET"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int t, n, q, a[mn], I[mn], f[mn], l[mn], r[mn], c[mn];
vector< ii> V[mn];

void up(int x)
{
    while(x<= n)
    {
        ++I[x];
        x+= (x& (- x));
    }
}

int get(int x)
{
    int ans= 0;
    while(x> 0){
        ans+= I[x];
        x-= (x& (- x));
    }
    return ans;
}

void RESET()
{
    memset(I, 0);
    memset(f, 0);
    a[n+ 1]= oo;
    forr(i, 1, n)
    V[i].clear();
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> t;
    while(t--){
        cin>> n>> q;
        RESET();
        forr(i, 1, n){
            cin>> a[i];
            if(a[i]!= a[i- 1]) l[i]= i;
            else l[i]= l[i- 1];
        }
        for(int i= n; i> 0; i--)
        {
            if(a[i]!= a[i+ 1]) r[i]= i;
            else r[i]= r[i+ 1];
        }
        forr(i, 1, q)
        {
            int u, v, k;
            cin>> u>> v>> k;
            c[i]= k;
            if(r[u]>= v){
                if(v- u+ 1>= k) f[i]= 1;
                continue;
            }
            if(r[u]- u+ 1>= k) ++f[i];
            if(v- l[v]+ 1>= k) ++f[i];
            V[r[u]].pb(ii(i, -1));
            V[l[v]- 1].pb(ii(i, 1));
        }
        forr(i, 1, n)
        {
            if(a[i]!= a[i+ 1]){
                up(n- i+ l[i]);
                for(auto z: V[i])
                {
                    int u= z.x;
                    f[u]+= z.y* get(n- c[u]+ 1);
                }
            }
        }
        forr(i, 1, q)
        cout<< f[i]<< "\n";
    }

    return 0;
}
