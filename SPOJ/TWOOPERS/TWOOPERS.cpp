//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 100005
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "TWOOPERS"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n, a[2* mn], c[mn], p[mn], res= 0;
string s, t;

int mod(int x)
{
    x%= oo;
    while(x< 0) x+= oo;
    return x;
}

int geta(int l, int r)
{
    int t= r- l+ 1;
    return mod(a[r]- p[t]* a[l- 1]);
}

int getc(int l, int r)
{
    int t= r- l+ 1;
    return mod(c[r]- p[t]* c[l- 1]);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> s>> t;

    n= s.size();

    s= " "+ s+ s;
    t= " "+ t;

    p[0]= 1;
    forr(i, 1, n)
        p[i]= (p[i- 1]* 29)% oo;

    forr(i, 1, 2* n)
        a[i]= (a[i- 1]* 29+ s[i])% oo;

    forr(i, 1, n)
        c[i]= (c[i- 1]* 29+ t[i])% oo;

    forr(i, 1, n)
    {
        int l= 0, r= n+ 1;
        while(r- l> 1){
            int m= (l+ r)/ 2;
            if(geta(i, i+ m- 1)== c[m]) l= m;
            else r= m;
        }
        if(l== n) res+= n;
        else{
            if(geta(i+ l+ 1, i+ n- 1)== getc(l+ 1, n))
                ++res;
        }
    }

    cout<< res;

    return 0;
}
