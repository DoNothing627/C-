//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 600005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "SEGMENT"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n, q, h[mn], l[mn], r[mn], a[mn], b[mn], p[mn][21], m= 0;


void rmq()
{
    forr(k, 1, 20)
    {
        forr(i, 1, m)
        {
            int u= lower_bound(h+ 1, h+ m+ 1, p[i][k- 1]+ 1)- h;
            p[i][k]= p[u][k- 1];
        }
    }
}


bool chek(int i, int c)
{
    int u= a[i];
    forr(k, 0, 20)
    {
        if((c>> k)& 1){
            u= p[u][k];
            if(u>= b[i]) return 1;
            ++u;
            u= lower_bound(h+ 1, h+ m+ 1, u)- h;
        }
    }
    return 0;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    cin>> n;
    forr(i, 1, n)
    {
        cin>> l[i]>> r[i];
        h[++m]= l[i], h[++m]= r[i]+ 1;
        //c= max(c, r[i]);
    }

    cin>> q;
    forr(i, 1, q)
    {
        cin>> a[i]>> b[i];
        h[++m]= a[i];
        //c= max(c, b[i]);
    }

    sort(h+ 1, h+ m+ 1);

    //forr(i, 1, m) p[i][0]= i;
    forr(i, 1, n)
    {
        l[i]= lower_bound(h+ 1, h+ m+ 1, l[i])- h;
        //r[i]= lower_bound(h+ 1, h+ m+ 1, r[i])- h;
        p[l[i]][0]= r[i];

    }

    forr(i, 1, m)
    {
        p[i][0]= max(p[i][0], p[i- 1][0]);
    }

    rmq();

    forr(i, 1, q)
    {
        a[i]= lower_bound(h+ 1, h+ m+ 1, a[i])- h;
        //b[i]= lower_bound(h+ 1, h+ m+ 1, b[i])- h;
        int L= 0, R= n+ 1;
        while(R- L> 1)
        {
            int mid= (L+ R)/ 2;
            if(chek(i, mid)) R= mid;
            else L= mid;
        }
        if(R== n+ 1) cout<< "-1\n";
        else cout<< R<< "\n";
    }
    return 0;
}
