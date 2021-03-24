//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define X first
#define Y second
#define mn
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1230C"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, m, res= 0, c[10], cnt= 0;
bool chek[10], d[10][10];
vector< ii> a;

void calc()
{
    int ans= 0;

    memset(d, 0);
    forr(j, 1, 6)
    forr(i, 0, m- 1)
    //if(a[i].X!= 7&& a[i].Y!= 7) ++ans;
    {
        if(c[a[i].X]== 7) c[a[i].X]= j;
        if(c[a[i].Y]== 7) c[a[i].Y]= j;
        if(!d[c[a[i].X]][c[a[i].Y]]) ++ans;
        d[c[a[i].X]][c[a[i].Y]]= d[c[a[i].Y]][c[a[i].X]]= 1;
    }

    /*if(ans== 15) //cout<< c[1]<< " "<< c[2]<< " "<< c[3]<< " "<< c[4]<< " "<< c[5]<< " "<< c[6]<< " "<< c[7]<< "\n";
        ++cnt;*/

    res= max(res, ans);
}

void cow(int x)
{
    if(!x){
        calc();
        return;
    }

    forr(i, 1, 7)
        if(!chek[i]){
            chek[i]= 1;
            c[x]= i;
            cow(x- 1);
            chek[i]= 0;
        }

}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> m;

    forr(i, 1, m)
    {
        int u, v;
        cin>> u>> v;
        a.pb(ii(u, v));
    }

    cow(n);

    cout<< res;

    return 0;
}
