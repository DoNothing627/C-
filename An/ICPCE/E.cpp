//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 50005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "E"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, m, h[mn], ANS[mn], I[mn], a[mn];

struct data
{
    int l, r, u, v, id;
}p[mn];

bool srt(data A, data B)
{
    return A.l< B.l;
}

bool cmp(data A, data B)
{
    return A.r< B.r;
}

void jump(int x)
{
    int L= p[x].l;
    while(L< p[x+ 1].l){
        int pts= lower_bound(h+ 1, h+ n+ 1, I[a[L]])- h;
        if(L) --h[pts], --I[a[L]];
        ++L;
    }
    L= p[x].l;
    while(L> p[x+ 1].l){
        --L;
        int pts= upper_bound(h+ 1, h+ n+ 1, I[a[L]])- h;
        ++h[pts- 1], ++I[a[L]];
    }
    L= p[x].r;
    while(L> p[x+ 1].r){
        int pts= lower_bound(h+ 1, h+ n+ 1, I[a[L]])- h;
        --h[pts], --I[a[L]];
        --L;
    }
    L= p[x].r;
    while(L< p[x+ 1].r){
        ++L;
        int pts= upper_bound(h+ 1, h+ n+ 1, I[a[L]])- h;
        ++h[pts- 1], ++I[a[L]];
    }
}

int calc(int i)
{
    int L= lower_bound(h+ 1, h+ n+ 1, p[i].u)- h;
    int R= upper_bound(h+ 1, h+ n+ 1, p[i].v)- h;
    return R- L;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    //freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n;
    forr(i, 1, n)
    {
        cin>> a[i];
        h[i]= a[i];
    }

    sort(h+ 1, h+ n+ 1);
    forr(i, 1, n)
        a[i]= lower_bound(h+ 1, h+ n+ 1, a[i])- h;

    memset(h, 0);
    cin>> m;
    forr(i, 1, m)
    {
        cin>> p[i].l>> p[i].r>> p[i].u>> p[i].v;
        p[i].id= i;
    }

    /*forr(i, 1, m)
        cout<< p[i].l<< " "<< p[i].r<< " "<< p[i].u<< " "<< p[i].v<< "\n";*/

    sort(p+ 1, p+ m+ 1, srt);

    int dist= sqrt(n)+ 1, point= 0, dem= 0, L, R= 1;
    //h[n]= 1, I[];
    while(point<= m){
        ++dem, L= R;
        while(point<= m&& p[point].l<= dist* dem) ++point;
        R= point;
        sort(p+ L, p+ R, cmp);
        for(int i= L; i< R; i++)
        {
            jump(i- 1);
            ANS[p[i].id]= calc(i);
        }
    }

    for(int i= 1; i<= m; i++) cout<< ANS[i]<< "\n";

    return 0;
}
