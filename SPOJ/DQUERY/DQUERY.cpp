//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 200005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "DQUERY"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, q, c[mn], d[10* mn], COUNT, ans[mn];
typedef pair< int, ii> iii;
iii a[mn];

void up(int u)
{
    ++d[c[u]];
    if(d[c[u]]== 1) ++COUNT;
}

void down(int u)
{
    --d[c[u]];
    if(d[c[u]]== 0) --COUNT;
}

bool cmpx(iii A, iii B)
{
    return A.y.x< B.y.x;
}

bool cmpy(iii A, iii B)
{
    return A.y.y< B.y.y;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n;
    forr(i, 1, n)
    cin>> c[i];

    cin>> q;
    forr(i, 1, q)
    {
        cin>> a[i].y.x>> a[i].y.y;
        a[i].x= i;
    }

    int m= sqrt(n), l= 1, r= 1;

    sort(a+ 1, a+ q+ 1, cmpx);

    forr(i, 1, m+ 1)
    {
        while(r<= q&& a[r].y.x<= m* i)
            ++r;
        sort(a+ l, a+ r, cmpy);
        forr(j, l, r- 1){
            int u= a[j- 1].y.y;
            while(u< a[j].y.y) ++u, up(u);
            while(u> a[j].y.y) down(u), --u;
            u= a[j- 1].y.x;
            while(u< a[j].y.x) down(u), ++u;
            while(u> a[j].y.x) --u, up(u);
            ans[a[j].x]= COUNT;
        }
        l= r;
    }

    forr(i, 1, q)
    cout<< ans[i]<< "\n";

    return 0;
}
