//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 100005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "DRASHOOT"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n, I[4* mn], bit[mn], a[mn];



void init(int k, int l, int r)
{
    if(l== r){
       I[k]= a[l];
       return;
    }
    int m= (l+ r)/ 2;
    init(2* k, l, m);
    init(2* k+ 1, m+ 1, r);
    I[k]= max(I[2* k], I[2* k+ 1]);
}

void upit(int k, int l, int r, int u)
{
    if(l> u|| r< u) return;
    if(l== r){
        I[k]= -oo;
        return;
    }
    int m= (l+ r)/ 2;
    upit(2* k, l, m, u);
    upit(2* k+ 1, m+ 1, r, u);
    I[k]= max(I[2* k], I[2* k+ 1]);
}

int getit(int k, int l, int r, int u, int v)
{
    if(l> v|| r< u) return -oo;
    if(l>= u&& r<= v)
        return I[k];
    int m= (l+ r)/ 2;
    return max(getit(2* k, l, m, u, v), getit(2* k+ 1, m+ 1, r, u, v));
}


void up(int x)
{
    while(x<= n)
    {
        ++bit[x];
        x+= (x& (- x));
    }
}

int get(int x)
{
    int ans= 0;
    while(x> 0)
    {
        ans+= bit[x];
        x-= (x& (- x));
    }
    return ans;
}

void read()
{
    int c;
    cin>> c;
    int l= 0, r= n;
    while(r- l> 1){
        int m= (l+ r)/ 2;
        if(m- get(m- 1)<= c) l= m;
        else r= m;
    }
    up(l);
    upit(1, 1, n, l);
}


void print()
{
    int c, L, R;
    cin>> c;
    if(c< 0){
        cout<< "NONE\n";
        return;
    }
    int l= 0, r= n+ 1;
    while(r- l> 1){
        int m= (l+ r)/ 2;
        if(get(m- 1)>= c) r= m;
        else l= m;
    }
    L= r;
    cin>> c;
    ++c;
    if(c< 0|| L== n+ 1){
        cout<< "NONE\n";
        return;
    }
    l= 0, r= n+ 1;
    while(r- l> 1){
        int m= (l+ r)/ 2;
        if(get(m- 1)>= c) r= m;
        else l= m;
    }
    R= r- 1;
    int ans= getit(1, 1, n, L, R);
    if(ans== -oo) cout<< "NONE\n";
    else cout<< ans<< "\n";
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n;
    forr(i, 1, n) cin>> a[i];

    init(1, 1, n);

    int m;
    cin>> m;
    while(m--){
        char c;
        cin>> c;
        if(c== 'S') read();
        else print();
    }

    return 0;
}
