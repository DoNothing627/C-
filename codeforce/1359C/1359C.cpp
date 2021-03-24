//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1359C"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int q, h, c, t;


bool chek(int m, bool type)
{
    int a= h* m+ c* (m- 1);
    if(type){
        if(a<= t* (2* m- 1)) return 1;
        return 0;
    }
    if(a>= t* (2* m- 1)) return 1;
        return 0;
}

double calc(int m)
{
    double f= (h* m+ c* (m- 1))/ (2* m- 1);
    f-= t;
    if(f<= 0) f= -f;
    return f;
}


main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> q;
    while(q--){
        cin>> h>> c>> t;
        int res;
        bool type= 0;
        if(h> (2* h+ c)/ 3) type= 1;
        int l= 0, r= 1000000;
        while(r- l> 1){
            int m= (l+ r)/ 2;
            if(chek(m, type)) r= m;
            else l= m;
        }
        if(calc(r)< calc(r+ 1)) res= r;
        res= r+ 1;
        double a= (h+ c)/ 2- t;
        //cout<< a<< " "<< res<< "\n";
        if(a< calc(res)) cout<< 2<< "\n";
        else cout<< 2* res+ 1<< "\n";
    }

    return 0;
}
