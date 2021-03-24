//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "VALUESTR"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n, c;
string s;

bool chek(int m)
{
    int res= 0, a= 0, b= 0;
    forr(i, 1, m)
    {
        if(s[i]== 'b'){
            res+= a;
            ++b;
        }
        if(s[i]== 'a') ++a;
    }
    if(res<= c) return 1;
    forr(i, m+ 1, n)
    {
        if(s[i- m]== 'a'){
            res-= b;
            --a;
        }
        if(s[i- m]== 'b') --b;
        if(s[i]== 'a') ++a;
        if(s[i]== 'b'){
            res+= a;
            ++b;
        }
        if(res<= c) return 1;
    }
    return 0;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    //freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> c>> s;
    s= " "+ s;
    int l= 1, r= n+ 1;

    while(r- l> 1)
    {
        int m= (l+ r)/ 2;
        if(chek(m)) l= m;
        else r= m;
    }

    cout<< l;

    return 0;
}
