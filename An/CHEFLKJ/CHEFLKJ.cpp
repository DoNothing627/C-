//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 200005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "CHEFLKJ"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n, m= 0, h[mn], l[mn], r[mn], a[mn];
set< int> s[mn];

bool chek(int i)
{
    int t= r[i]- l[i]+ 1, L, R;
    forr(k, 0, 19)
    {
        int u= l[i]+ rand()% t;
        L= s[a[u]].lower_bound(l[i]);
        R= s[a[u]].upper_bound(r[i]);
        if(R- L> t/ 2) return 1;
    }
    return 0;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> q;
    forr(i, 1, n){
        cin>> a[i];
        h[++m]= a[i];
    }
    forr(i, 1, q)
    {
        cin>> type[i]>> l[i]>> r[i];
        if(type[i]== 1) h[++m]= r[i];
    }

    sort(h+ 1, h+ m+ 1);

    forr(i, 1, n)
    {
        a[i]= lower_bound(h+ 1, h+ m+ 1, a[i])- h;
        s[i].insert(i);
    }

    forr(i, 1, q)
    {
        if(type[i]== 1)
        {
            s[a[l[i]]].erase(i);
            r[i]= lower_bound(h+ 1, h+ m+ 1, r[i])- h;
            a[l[i]]= r[i];
            s[r[i]].insert(l[i]);
        }
        else{
            if(chek(i)) cout<< "YES\n";
            else cout<< "NO\n";
        }
    }

    return 0;
}
