//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "1325D"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int u, v, a[3], res= 0, p[70];

bool d[70];
//vector< int> a;

/*void rcs(int u, int v)
{

}*/

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> u>> v;

    //rcs(u, v);

    a[0]= u;
    v-= u;

    if(v< 0){
        cout<< -1;
        return 0;
    }

    p[0]= 1;

    forr(i, 1, 60) p[i]= p[i- 1]* 2;

    forr(i, 0, 60)
    {
        if(((u>> i)& 1)== 1) d[i]= 1;
        if(((v>> i)& 1)== 1){
            if(i== 0){
                cout<< -1;
                return 0;
            }
            if(!d[i- 1]){
                a[0]+= p[i- 1];
                a[1]+= p[i- 1];
                d[i- 1]= 1;
            }
            else{
                a[2]+= p[i- 1];
                a[1]+= p[i- 1];
            }
        }
    }

    forr(i, 0, 2) if(a[i]) ++res;

    cout<< res<< "\n";
    forr(i, 0, res- 1) cout<< a[i]<< " ";

    //cout<< (1<< 40);

    return 0;
}
