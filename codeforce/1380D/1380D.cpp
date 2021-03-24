//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 200005
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "1380D"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, m, a[2* mn], b[mn], res= 0, x, y, k, v[mn], flag= 0;
bool type= 0;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> m>> x>> k>> y;
    forr(i, 1, n){
        cin>> a[i];
        a[i+ n+ 1]= a[i];
    }
    a[n+ 1]= 0;
    forr(i, 1, m) cin>> b[i];
    b[++m]= 0, b[++m]= b[1];

    if(x> k* y) type= 1;

    int l= 1, r, point= 1;
    while(a[l]!= b[1]) ++l;
    r= l;
    while(point< m){
        l= r;
        int cnt= 0, ans= 0;
        ++point;
        while(a[r]!= b[point]){
            ++r;
            if(a[r]> b[point]&& a[r]> b[point- 1]) v[++cnt]= r;
        }
        int length= r- l- 1;
        //v[cnt+ 1]= oo;
        if(type&& cnt){
            res+= (length- k)* y+ x;
            if(length< k) goto END;
        }
        if(type&& !cnt) res+= length* y;
        if(!type){
            for(int i= 1; i<= cnt; )
            {
                int u= v[i];
                int id= upper_bound(v+ i, v+ cnt+ 1, u+ k- 1)- v;
                --id;
                if(id== cnt&& length< k)
                    goto END;
                length-= k, res+= x;
                i= id+ 1;
            }
            //res+= ans* x;
            res+= (length/ k)* x+ (length% k)* y;
        }

        if(r> n+ 1) ++flag;
        if(flag> 1) goto END;
    }

    cout<< res;
    return 0;

    END:

    cout<< -1;

    return 0;
}
