//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 100005
#define pb push_back
#define oo 100000000007
#define int long long
#define DoNothing "MSAVING"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;


int n, m, p, q, r[mn], R[mn], ans= 0, res= 0, _ans= 0;



struct iii
{
    int u, v, w;
    iii(){};
    iii(int _u, int _v, int _w)
    {
        u= _u, v= _v, w= _w;
    }
};

vector< iii> a, b;

bool cmp(iii A, iii B)
{
    return A.w< B.w;
}


int fs(int u)
{
    return !r[u]? u: r[u]= fs(r[u]);
}

int FS(int u)
{
    return !R[u]? u: R[u]= FS(R[u]);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    cin>> n>> m>> p>> q;
    forr(i, 1, p)
    {
        int u, v, w;
        cin>> u>> v>> w;
        res+= w* n;
        a.pb(iii(u, v, w));
    }

    sort(a.begin(), a.end(), cmp);
    forr(i, 0, a.size()- 1)
    {
        int u= a[i].u, v= a[i].v, w= a[i].w;
        int fu= fs(u), fv= fs(v);
        if(fu!= fv){
            r[fu]= fv;
            ans+= w;
        }
    }



    forr(i, 1, q)
    {
        int u, v, w;
        cin>> u>> v>> w;
        res+= w* m;
        b.pb(iii(u, v, w));
    }

    sort(b.begin(), b.end(), cmp);

    memset(r, 0);
    int i= 0, cnt= m;
    forr(j, 0, b.size()- 1)
    {
        int u= b[j].u, v= b[j].v, w= b[j].w;
        int fu= FS(u), fv= FS(v);
        if(fu== fv) continue;
        R[fu]= fv;

        while(w>= a[i].w&& i< p)
        {
            u= a[i].u, v= a[i].v;
            fu= fs(u), fv= fs(v);
            ++i;
            if(fu== fv) continue;
            r[fu]= fv;
            _ans+= a[i- 1].w;
            --cnt;
        }
        ans+= _ans+ w* cnt;
    }

    cout<< res- ans;

    return 0;
}
