//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 200005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1260D"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int m, n, k, t, a[mn], id[mn], F[mn], G[mn];

struct data
{
    int l, r, d;
}p[mn];

bool cmp(data A, data B)
{
    return A.d< B.d;
}


bool chek(int M){

    int L= lower_bound(id+ 1, id+ k+ 1, a[m- M+ 1]+ 1)- id;

    int ans= 2* (F[L]- G[L]+ 1);

    return ans+ n<= t;

}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> m>> n>> k>> t;

    forr(i, 1, m) cin>> a[i];
    sort(a+ 1, a+ m+ 1);

    forr(i, 1, k)
        cin>> p[i].l>> p[i].r>> p[i].d;

    sort(p+ 1, p+ k+ 1, cmp);

    G[k+ 1]= oo;
    for(int i= k; i> 0; i--)
    {
        F[i]= max(F[i+ 1], p[i].r);
        G[i]= min(G[i+ 1], p[i].l);
    }

    forr(i, 1, k) id[i]= p[i].d;

    /*forr(i, 1, k)
         v[p[i].l].pb(ii(i, p[i].r));
    forr(i, 1, n)
        sort(v[i].begin(), v[i].end(), srt);*/

    int L= 0, R= m+ 1;

    while(R- L> 1){
        int M= (L+ R)/ 2;
        if(chek(M)) L= M;
        else R= M;
    }

    cout<< L;
    return 0;
}
