//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 10000005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "VECTOR"
#define PI 3.1415926535897
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, m, d[mn], COUNT= 0, TRUE[mn], a[mn], c[mn];
vector< ii> res;

void snt()
{
    forr(i, 2, 1e7)
    {
        if(!d[i]){
            d[i]= ++COUNT;
            TRUE[COUNT]= i;
            for(long long j= 1ll* i* i; j<= 1e7; j+= i)
                d[j]= COUNT;
        }
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    snt();
    cin>> n;
    while(n--){
        int u;
        cin>> u;
        while(u!= 1){
            ++a[d[u]];
            u/= TRUE[d[u]];
        }
    }

    cin>> m;
    while(m--){
        int u;
        cin>> u;
        while(u!= 1){
            ++c[d[u]];
            u/= TRUE[d[u]];
        }
    }

    //cout<< COUNT;

    forr(i, 1, COUNT)
    {
        int u= c[i], v= a[i];
        while(u% 2|| (u/ 2)% 2!= v% 2){
            res.pb(ii(1, TRUE[i]));
            ++u;
        }
        while(u){
            res.pb(ii(0, TRUE[i]));
            ++v;
            u-= 2;
        }
        while(v){
            res.pb(ii(2, TRUE[i]));
            v-= 2;
        }
    }

    cout<< res.size()<< "\n";
    for(auto z: res)
    {
        cout<< z.y<< " ";
        if(z.x== 0) cout<< "W";
        else{
            if(z.x== 1) cout<< "D";
            else cout<< "L";
        }
        cout<< "\n";
    }
    return 0;
}
