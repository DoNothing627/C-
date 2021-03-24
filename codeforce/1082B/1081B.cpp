//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 200005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1081B"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n, I[mn], l[mn], r[mn];
char a[mn];

void up(int x)
{
    while(x<= n)
    {
        ++I[x];
        x+= (x& (- x));
    }
}

int get(int x)
{
    int ans= 0;
    while(x> 0)
    {
        ans+= I[x];
        x-= (x& (- x));
    }
    return ans;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n;

    forr(i, 1, n){
        cin>> a[i];
        if(a[i]== 'G'){
            l[i]= l[i- 1]+ 1;
            up(i);
        }
        else l[i]= 0;
    }

    for(int i= n; i> 0; i--)
    {
        if(a[i]== 'G') r[i]= r[i+ 1]+ 1;
        else r[i]= 0;
    }

    int res= r[1];
    forr(i, 1, n)
    {
        if(a[i]== 'S'){
            res= max(res, l[i- 1]+ r[i+ 1]);
            int c= get(n)- get(i+ r[i+ 1]);
            int d= get(i- 1- l[i- 1]);
            if(c|| d) res= max(res, l[i- 1]+ r[i+ 1]+ 1);
        }
    }

    cout<< res;
    return 0;
}
