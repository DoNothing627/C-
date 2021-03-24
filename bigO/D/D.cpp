//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 100005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "D"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, q, r[mn], a[mn], h[mn], f[mn], COUNT= 0;
bool chek[mn];
vector< int> v[mn], z[mn];

int fs(int u)
{
    return !r[u] ? u: fs(r[u]);
}

void doIt(int U, int V)
{
    int fu= fs(U), fv= fs(V);
    if(v[fu].size()> v[fv].size()) swap(fu, fv);
    for(int u: v[fu]){
        int id= binary_search(v[fv].begin(), v[fu].end(), u);
        if(id) f[u]--;
    }
    for(int u: v[fu]){
        int id= binary_search(v[fv].begin(), v[fu].end(), u);
        if(!id) v[fv].pb(u);
    }
    sort(v[fv].begin(), v[fv].end());
    r[fu]= fv;
}

void cow()
{
    while(q--){
        int x, y, type;
        cin>> type;
        if(type== 1){
            cin>> x>> y;
            doIt(x, y);
        }
        else{
            cin>> x;
            x= lower_bound(h+ 1, h+ n+ 1, x)- h;
            cout<< f[x]<< "\n";
        }
    }
}

void buff()
{
    while(q--){
        int x, y, type, res= 0;
        cin>> type;
        if(type== 1){
            cin>> x>> y;
            //doIt(x, y);
            r[x]= y;
        }
        else{
            cin>> x;
            x= lower_bound(h+ 1, h+ n+ 1, x)- h;
            //cout<< f[x]<< "\n";
            for(int u: z[x]){
                int fu= fs(u);
                if(!chek[fu]) ++res;
                chek[fu]= 1;
            }
            for(int u: z[x]){
                int fu= fs(u);
                chek[fu]= 0;
            }
            cout<< res<< "\n";
        }
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> q;

    forr(i, 1, n)
        cin>> a[i], h[i]= a[i];

    sort(h+ 1, h+ n+ 1);
    forr(i, 1, n){
        a[i]= lower_bound(h+ 1, h+ n+ 1, a[i])- h;
        ++f[a[i]];
        v[i].pb(a[i]);
        z[a[i]].pb(i);
    }

    forr(i, 1, n) if(f[i]) ++COUNT;

    //cout<< chek[5]<< "\n";
    /*if(COUNT< sqrt(n)) cow();
    else buff();*/

    buff();

    return 0;
}
